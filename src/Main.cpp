
#include <iostream>


#include "Project.h"
// Can comment this one out and define another macro to remove all tests
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "config4cpp/ConfigurationException.h"
#include "config4cpp/Configuration.h"
#include "log4cxx/logger.h"
#include "optparse.h"


int main(int argc, char** argv) {

    // OptParse - Header Only, and modified from github page
    optparse::OptionParser parser = optparse::OptionParser().description("Main.cpp argument parser");
    parser.add_option("--configFile") \
          .dest("configFile") \
          .action("store") \
          .type("string") \
          .set_default("../config/MainConfig.cfg") \
          .help("filepath to config FILE to be parsed by config4cpp") \
          .metavar("FILE");
    parser.add_option("--logFile")
          .dest("logFile")
          .action("store")
          .type("string")
          .set_default("../config/Log4Cxx.cfg")
          .help("filepath to log config FILE to be parsed by Log4Cxx")
          .metavar("FILE");

    optparse::Values options = parser.parse_args(argc, argv);
    std::vector<std::string> parsedArgs = parser.args();

    if (!options.get("configFile").getStr().empty()) {
        std::cout << "ConfigFile: " << options["configFile"] << std::endl;
    }
    if (!options.get("logFile").getStr().empty()) {
        std::cout << "LogFile: " << options["logFile"] << std::endl;
    }


    // Config4Cpp library
    config4cpp::Configuration *configuration = config4cpp::Configuration::create();
    const char* exampleString = "";
    try {
        configuration->parse(options["configFile"].c_str());
        exampleString = configuration->lookupString("", "exampleString");
    } catch (const config4cpp::ConfigurationException &except) {
        std::cerr << except.c_str() << std::endl;
        configuration->destroy();
        return 1;
    }
    std::cout << "Value of exampleString from config is: ";
    std::cout << exampleString << std::endl;


    // Doctest boilerplate
    doctest::Context context;
    context.addFilter("test-case-exclude", "*math"); // exclude test cases with "math" in their name
    context.setOption("abort-after", 5); // stop test execution after 5 failed assertions
    context.setOption("order-by", "name"); // sort the test cases by their name
    context.applyCommandLine(argc, argv);
    // Doctest overrides
    context.setOption("no-breaks", true); // don't break in the debugger when asserts fail
    // Doctest boilerplate
    int doctestReturn = context.run(); // run tests
    if (context.shouldExit()) { // important - query flags (and --exit) rely on doing this
        return doctestReturn; // propagate the result of the tests
    }



    int projectReturn = 0;

    std::cout << "Hello world!" << std::endl;
    return doctestReturn + projectReturn;
}
