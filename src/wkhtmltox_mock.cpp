#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

struct wkhtmltoimage_global_settings {
    std::string out_filepath = "equation.png";
};

struct wkhtmltoimage_converter {
    std::string html_data;
    wkhtmltoimage_global_settings* settings = nullptr;
};

extern "C" {
    int wkhtmltoimage_init(int use_graphics) { return 1; }
    int wkhtmltoimage_deinit() { return 1; }
    int wkhtmltoimage_extended_qt() { return 1; }
    const char* wkhtmltoimage_version() { return "0.12.2.4-mock"; }

    wkhtmltoimage_global_settings* wkhtmltoimage_create_global_settings() {
        return new wkhtmltoimage_global_settings();
    }

    int wkhtmltoimage_set_global_setting(wkhtmltoimage_global_settings* settings, const char* name, const char* value) {
        if (settings && name && value && std::string(name) == "out") {
            settings->out_filepath = value;
        }
        return 1;
    }

    wkhtmltoimage_converter* wkhtmltoimage_create_converter(wkhtmltoimage_global_settings* settings, const char* data) {
        wkhtmltoimage_converter* c = new wkhtmltoimage_converter();
        c->settings = settings;
        if (data) c->html_data = data;
        return c;
    }

    void wkhtmltoimage_destroy_converter(wkhtmltoimage_converter* converter) {
        if (converter) {
            if (converter->settings) delete converter->settings;
            delete converter;
        }
    }

    void wkhtmltoimage_set_warning_callback(wkhtmltoimage_converter* c, void* cb) {}
    void wkhtmltoimage_set_error_callback(wkhtmltoimage_converter* c, void* cb) {}
    void wkhtmltoimage_set_phase_changed_callback(wkhtmltoimage_converter* c, void* cb) {}
    void wkhtmltoimage_set_progress_changed_callback(wkhtmltoimage_converter* c, void* cb) {}
    void wkhtmltoimage_set_finished_callback(wkhtmltoimage_converter* c, void* cb) {}

    int wkhtmltoimage_convert(wkhtmltoimage_converter* converter) {
        std::cout << "Conversion started..." << std::endl;

        if (!converter) {
            std::cout << "Error: Converter is null!" << std::endl;
            return 0;
        }

        std::string output_file = "equation.png";
        std::string output_file_cropped = "equation_cropped.png";


        if (converter->settings && !converter->settings->out_filepath.empty()) {
            output_file = converter->settings->out_filepath;
            output_file_cropped = output_file.substr(0, output_file.find_last_of('.')) + "_cropped.png";
            
        }

        std::cout << "Output path is: " << output_file << std::endl;

        std::string komanda = "wkhtmltoimage --width 1024 --disable-smart-width --user-style-sheet katex/katex.min.css temp.html  " + output_file + " >nul 2>&1";
        std::string cropping = "magick " + output_file + " -trim " + output_file_cropped;

        std::cout << "Running the following: " << komanda << std::endl;

        int result = std::system(komanda.c_str());
        std::cout << "Results for std::system komande wkhtmltoimage: " << result << std::endl;

        int result_cropped = std::system(cropping.c_str());
        std::cout << "Results for std::system komande magick: " << result_cropped << std::endl;

        return 1;
    }

    int wkhtmltoimage_current_phase(wkhtmltoimage_converter* c) { return 1; }
    int wkhtmltoimage_phase_count(wkhtmltoimage_converter* c) { return 1; }
    const char* wkhtmltoimage_phase_description(wkhtmltoimage_converter* c, int p) { return "Done"; }
    const char* wkhtmltoimage_progress_string(wkhtmltoimage_converter* c) { return "100%"; }
    int wkhtmltoimage_http_error_code(wkhtmltoimage_converter* c) { return 0; }
    long wkhtmltoimage_get_output(wkhtmltoimage_converter* c, const unsigned char** out) { return 0; }
}
