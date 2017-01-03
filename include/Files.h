//
// Created by linde on 1/3/17.
//

#ifndef DATA_READING_FILES_H
#define DATA_READING_FILES_H

#include <string>
#include <fstream>
#include <iostream>

namespace FR {

    class Files {

    public:

        /**
         * This function checks to see if a file exists
         * If it does not exists if returns false
         * http://stackoverflow.com/a/19841704
         */
        static bool is_file_exist(std::string path) {
            std::ifstream infile(path.c_str());
            return infile.good();
        }

    };

}


#endif //DATA_READING_FILES_H
