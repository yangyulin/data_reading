//
// Created by linde on 1/3/17.
//

#include <vector>
#include <filereader.h>
#include "Files.h"



FR::filereader::filereader() {
}

FR::filereader::filereader(std::string datadir) {

    //generate file path
    std::string path_imu_times = datadir + "/" + "imu_times.txt";
    std::string path_Am = datadir + "/" + "Am.txt";
    std::string path_Ar = datadir + "/" + "Ar.txt";
    std::string path_Om = datadir + "/" + "Om.txt";
    std::string path_Or = datadir + "/" + "Or.txt";
    std::string path_xtk_log = datadir + "/" + "xtk_log.txt";
    std::string path_ImgTS = datadir + "/" + "ImgTS.txt";
    std::string path_ImgId = datadir + "/" + "ImgId.txt";
    std::string path_ImgPtsU = datadir + "/" + "ImgPtsU.txt";
    std::string path_ImgPtsV = datadir + "/" + "ImgPtsV.txt";
    std::string path_ImgPtsUm = datadir + "/" + "ImgPtsUm.txt";
    std::string path_ImgPtsVm = datadir + "/" + "ImgPtsVm.txt";
    std::string path_map_feat = datadir + "/" + "map_feat.txt";

    //check whether IMU files are there
    if(!FR::Files::is_file_exist(path_imu_times)    ||
            !FR::Files::is_file_exist(path_Am)      ||
            !FR::Files::is_file_exist(path_Om)      ||
            !FR::Files::is_file_exist(path_Ar)      ||
            !FR::Files::is_file_exist(path_Or)      ||
            !FR::Files::is_file_exist(path_xtk_log)){
        std::cerr << "[filereader]: Cannot find the IMU files!" << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_imu_times << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_Am << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_Om << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_Ar << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_Or << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_xtk_log << std::endl;
    }

    //check whether cam files are there
    if(!FR::Files::is_file_exist(path_ImgTS)    ||
       !FR::Files::is_file_exist(path_ImgId)    ||
       !FR::Files::is_file_exist(path_ImgPtsU)  ||
       !FR::Files::is_file_exist(path_ImgPtsV)  ||
       !FR::Files::is_file_exist(path_ImgPtsUm) ||
       !FR::Files::is_file_exist(path_ImgPtsVm)){
        std::cerr << "[filereader]: Cannot find the Cam files!" << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgTS << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgId << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgPtsU << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgPtsUm << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgPtsV << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_ImgPtsVm << std::endl;
    }

    //check whether map files are there
    if( !FR::Files::is_file_exist(path_map_feat)){
        std::cerr << "[filereader]: Cannot find the map files!" << std::endl;
        std::cerr << "[filereader]: Tried to find it at: " << path_map_feat << std::endl;
    }

    //Open the IMU file stream
    std::ifstream file_imu_times(path_imu_times);
    std::ifstream file_Am(path_Am);
    std::ifstream file_Ar(path_Ar);
    std::ifstream file_Om(path_Om);
    std::ifstream file_Or(path_Or);
    std::ifstream file_xtk_log(path_xtk_log);

    //Open the cam file stream
    std::ifstream file_ImgTS(path_ImgTS);
    std::ifstream file_ImgId(path_ImgId);
    std::ifstream file_ImgPtsU(path_ImgPtsU);
    std::ifstream file_ImgPtsV(path_ImgPtsV);
    std::ifstream file_ImgPtsUm(path_ImgPtsUm);
    std::ifstream file_ImgPtsVm(path_ImgPtsVm);

    //Open the map file stream
    std::ifstream file_map_feat(path_map_feat);

    ///read in the imu_data
    double timestamp;
    double a1, a2, a3;
    double w1, w2, w3;
    double q1, q2, q3, q4;
    double bg1, bg2, bg3;
    double v1, v2, v3;
    double ba1, ba2, ba3;
    double p1, p2, p3;
    double x1, x2, x3, x4, x5, x6;

    std::string tempStr;

    //read in the timestamp
    while(!file_imu_times.eof()){
        getline(file_imu_times, tempStr);
        sscanf(tempStr.c_str(), "%lf", &timestamp);
        imu_times.push_back(timestamp);
    }

    //read in the Am
    tempStr.clear();
    while(!file_Am.eof()){
        getline(file_Am, tempStr);
        sscanf(tempStr.c_str(), "%lf, %lf, %lf", &a1, &a2, &a3);
        Am.push_back(Eigen::Vector3d(a1,a2,a3));
    }
    //read in the Ar
    tempStr.clear();
    while(!file_Ar.eof()){
        getline(file_Ar, tempStr);
        sscanf(tempStr.c_str(), "%lf, %lf, %lf", &a1, &a2, &a3);
        Ar.push_back(Eigen::Vector3d(a1,a2,a3));
    }
    //read in the Om
    tempStr.clear();
    while(!file_Om.eof()){
        getline(file_Om, tempStr);
        sscanf(tempStr.c_str(), "%lf, %lf, %lf", &w1, &w2, &w3);
        Om.push_back(Eigen::Vector3d(w1,w2,w3));
    }
    //read in the Or
    tempStr.clear();
    while(!file_Or.eof()){
        getline(file_Or, tempStr);
        sscanf(tempStr.c_str(), "%lf, %lf, %lf", &w1, &w2, &w3);
        Or.push_back(Eigen::Vector3d(w1,w2,w3));
    }
    //read in the xtk_log
    tempStr.clear();
    Eigen::Matrix<double,22,1> tempImuState;
    while(!file_xtk_log.eof()){
        getline(file_xtk_log, tempStr);
        sscanf(tempStr.c_str(), "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                                &q1,&q2,&q3,&q4,&bg1,&bg2,&bg3,&v1,&v2,&v3,&ba1,&ba2,&ba3,&p1,&p2,&p3,&x1,&x2,&x3,&x4,&x5,&x6);
        tempImuState <<q1,q2,q3,q4,bg1,bg2,bg3,v1,v2,v3,ba1,ba2,ba3,p1,p2,p3,x1,x2,x3,x4,x5,x6;
        xtk_log.push_back(tempImuState);
    }

    ///read in the map information
    tempStr.clear();
    while(!file_map_feat.eof()){
        getline(file_map_feat, tempStr);
        sscanf(tempStr.c_str(), "%lf, %lf, %lf", &p1, &p2, &p3);
        map_feat.push_back(Eigen::Vector3d(p1,p2,p3));
    }

    ///read in the cam data
    std::vector<double> id;
    std::vector<double> val_u;
    std::vector<double> val_v;
    double temp;
    //read in the cam timestamp
    tempStr.clear();
    while(!file_ImgTS.eof()){
        getline(file_ImgTS, tempStr);
        sscanf(tempStr.c_str(), "%lf", &timestamp);
        ImgTS.push_back(timestamp);
    }

    //read in the measured camera data
    tempStr.clear();
    while(!file_ImgPtsUm.eof() || !file_ImgPtsVm.eof() || !file_ImgId.eof()){

        id.clear();
        val_u.clear();
        val_v.clear();
        //read id
        getline(file_ImgId,tempStr);
        std::stringstream sid(tempStr);
        while(sid >> temp){
            id.push_back(temp-1);
            if( sid.peek() == ','){
                sid.ignore();
            }
        }
        ImgId.push_back(id);

        //read val_u
        tempStr.clear();
        getline(file_ImgPtsUm,tempStr);
        std::stringstream sval_u(tempStr);
        while(sval_u >> temp){
            val_u.push_back(temp);
            if(sval_u.peek() == ','){
                sval_u.ignore();
            }
        }
        ImgPtsUm.push_back(val_u);

        //read val_v
        tempStr.clear();
        getline(file_ImgPtsVm,tempStr);
        std::stringstream sval_v(tempStr);
        while(sval_v >> temp){
            val_v.push_back(temp);
            if(sval_v.peek() == ','){
                sval_v.ignore();
            }
        }
        ImgPtsVm.push_back(val_v);

    }

    //read in the true cam data
    tempStr.clear();
    while(!file_ImgPtsU.eof() || !file_ImgPtsV.eof()){

        val_u.clear();
        val_v.clear();

        //read val_u
        tempStr.clear();
        getline(file_ImgPtsU,tempStr);
        std::stringstream sval_u(tempStr);
        while(sval_u >> temp){
            val_u.push_back(temp);
            if(sval_u.peek() == ','){
                sval_u.ignore();
            }
        }
        ImgPtsU.push_back(val_u);

        //read val_v
        tempStr.clear();
        getline(file_ImgPtsV,tempStr);
        std::stringstream sval_v(tempStr);
        while(sval_v >> temp){
            val_v.push_back(temp);
            if(sval_v.peek() == ','){
                sval_v.ignore();
            }
        }
        ImgPtsV.push_back(val_v);

    }
}

std::vector<double, std::allocator<double>> FR::filereader::getimu_times() {
    return imu_times;
}

std::vector<Eigen::Vector3d> FR::filereader::getAm() {
    return Am;
}

std::vector<Eigen::Vector3d> FR::filereader::getAr() {
    return Ar;
}

std::vector<Eigen::Vector3d> FR::filereader::getOm() {
    return Om;
}

std::vector<Eigen::Vector3d> FR::filereader::getOr() {
    return Or;
}

std::vector<Eigen::Matrix<double, 22, 1>> FR::filereader::getxtk_log() {
    return xtk_log;
}

std::vector<double> FR::filereader::getImgTS() {
    return ImgTS;
}

std::vector<std::vector<double>> FR::filereader::getImgId() {
    return ImgId;
}

std::vector<std::vector<double>> FR::filereader::getImgPtsU() {
    return ImgPtsU;
}

std::vector<std::vector<double>> FR::filereader::getImgPtsV() {
    return ImgPtsV;
}

std::vector<std::vector<double>> FR::filereader::getImgPtsUm() {
    return ImgPtsUm;
}

std::vector<std::vector<double>> FR::filereader::getImgPtsVm() {
    return ImgPtsVm;
}

std::vector<Eigen::Vector3d> FR::filereader::getmap_feat() {
    return map_feat;
}
