
#include<iostream>
#include "filereader.h"

using namespace std;

int main(){

    FR::filereader fr("/home/linde/data/Project/data_reading/simdata");

    std::cout<<"The test information of the reading results "<<std::endl;
    std::cout<<"Information about the IMU: "<<std::endl;
    std::cout<<"Size of imu_times "<<fr.getimu_times().size()<<std::endl;
    std::cout<<"Size of xtk_log "<<fr.getxtk_log().size()<<std::endl;
    std::cout<<"Size of Am "<<fr.getAm().size()<<std::endl;
    std::cout<<"Size of Om "<<fr.getOm().size()<<std::endl;
    std::cout<<"Size of Ar "<<fr.getAr().size()<<std::endl;
    std::cout<<"Size of Or "<<fr.getOr().size()<<std::endl;

    std::cout<<"Information about the Cam: "<<std::endl;
    std::cout<<"Size of ImgTS "<<fr.getImgTS().size()<<std::endl;
    std::cout<<"Size of ImgId "<<fr.getImgId().size()<<std::endl;
    std::cout<<"Size of ImgPtsU "<<fr.getImgPtsU().size()<<std::endl;
    std::cout<<"Size of ImgPtsV "<<fr.getImgPtsV().size()<<std::endl;
    std::cout<<"Size of ImgPtsUm "<<fr.getImgPtsUm().size()<<std::endl;
    std::cout<<"Size of ImgPtsVm "<<fr.getImgPtsVm().size()<<std::endl;

    std::cout<<"Information about the Map: "<<std::endl;
    std::cout<<"Size of map_feat "<<fr.getmap_feat().size()<<std::endl;

    return 0;
}
