#ifndef SENSOR_H
#define SENSOR_H

#include <QMainWindow>


#define SEC_SD_OFFSET       (0)
#define SEC_VD_LVD_OFFSET   (6)
#define SEC_VD_HVD_OFFSET   (7)
#define SEC_TD_LTD_OFFSET   (8)
#define SEC_TD_HTD_OFFSET	(9)
#define SEC_LD_OFFSET       (10)
#define SEC_FD2_LFD_OFFSET  (15)
#define SEC_FD2_HFD_OFFSET  (16)
#define SEC_FD3_LFD_OFFSET  (17)
#define SEC_FD3_HFD_OFFSET  (18)
#define SEC_ASH_OFFSET      (19)
#define SEC_EGS_OFFSET      (20)

QStringList err_list = {
    {"SEC_VD_LVD低压报警\n"},   //SEC_VD_LVD_OFFSET
    {"SEC_VD_HVD高压报警\n"},   //SEC_VD_HVD_OFFSET
    {"SEC_TD_LTD低温报警\n"},   //SEC_TD_LTD_OFFSET
    {"SEC_TD_HTD高温报警\n"},   //SEC_TD_HTD_OFFSET
    {"SEC_LD光检测报警\n"},        //SEC_LD_OFFSET
    {"SEC_FD2_LFD模块报警 \n"},   //SEC_FD2_LFD_OFFSET
    {"SEC_FD2_HFD模块报警\n"},   //SEC_FD2_HFD_OFFSET
    {"SEC_FD3_LFD模块报警\n"},   //SEC_FD3_LFD_OFFSET
    {"SEC_FD3_HFD模块报警\n"},   //SEC_FD3_HFD_OFFSET
    {"SEC_ASH模块报警\n"},       //SEC_ASH_OFFSET
    {"SEC_EGS电源电压检测模块报警\n"},      //SEC_EGS_OFFSET
};



#endif // SENSOR_H
