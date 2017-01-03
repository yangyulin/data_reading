//
// Created by linde on 1/3/17.
//

#ifndef DATA_READING_FILEREADER_H
#define DATA_READING_FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <Eigen/Eigen>
#include <Eigen/Core>
#include <Eigen/Dense>

#include <boost/thread.hpp>

namespace FR{
    class filereader{

    public:
        filereader();
        filereader(std::string datadir);
        //get IMU information
        std::vector<double> getimu_times();
        std::vector<Eigen::Vector3d> getAm();
        std::vector<Eigen::Vector3d> getAr();
        std::vector<Eigen::Vector3d> getOm();
        std::vector<Eigen::Vector3d> getOr();
        std::vector<Eigen::Matrix<double, 22,1>> getxtk_log();
        //get cam information
        std::vector<double> getImgTS();
        std::vector< std::vector<double>> getImgId();
        std::vector< std::vector<double>> getImgPtsU();
        std::vector< std::vector<double>> getImgPtsV();
        std::vector< std::vector<double>> getImgPtsUm();
        std::vector< std::vector<double>> getImgPtsVm();
        //map information
        std::vector<Eigen::Vector3d> getmap_feat();


    protected:

        std::string datadir;

        //IMU data
        std::vector<double> imu_times;
        std::vector<Eigen::Vector3d> Am;
        std::vector<Eigen::Vector3d> Ar;
        std::vector<Eigen::Vector3d> Om;
        std::vector<Eigen::Vector3d> Or;
        std::vector<Eigen::Matrix<double, 22,1>> xtk_log;

        //cam data
        std::vector<double> ImgTS;
        std::vector< std::vector<double>> ImgId;
        std::vector< std::vector<double>> ImgPtsU;
        std::vector< std::vector<double>> ImgPtsV;
        std::vector< std::vector<double>> ImgPtsUm;
        std::vector< std::vector<double>> ImgPtsVm;

        //map information
        std::vector<Eigen::Vector3d> map_feat;
    };
}


#endif //DATA_READING_FILEREADER_H
