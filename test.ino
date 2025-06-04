#include <Dynamixel2Arduino.h>

using namespace ControlTableItem;
// #define DXL_SERIAL Serial1                       // 用于与Dynamixel舵机通信的串口
HardwareSerial SerialPort(1); // 使用UART1                                // Dynamixel舵机的ID
const uint8_t DXM_ID=1;                                // Dynamixel舵机的ID
const float DXL_PROTOCOL_VERSION = 2.0;          // Dynamixel协议版本
const int DXL_DIR_PIN = 12; // DYNAMIXEL Shield DIR PIN
Dynamixel2Arduino dxl(SerialPort,DXL_DIR_PIN); 

void setup() {
  Serial.begin(115200);

  SerialPort.begin(1000000, SERIAL_8N1, 11, 13); 

  dxl.begin(1000000);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);  // 设置Dynamixel舵机的协议版本
  dxl.ping(DXM_ID);                         // 发送ping命令以检测Dynamixel舵机的连接状态
  dxl.torqueOff(DXM_ID);              // 关闭Dynamixel舵机的扭力
  dxl.setOperatingMode(DXM_ID, OP_VELOCITY);  // 设置Dynamixel舵机的操作模式为位置模式     
  dxl.torqueOn(DXM_ID);                // 开启Dynamixel舵机的扭力
  //dxl.writeControlTableItem(PROFILE_VELOCITY, DXM_ID, 30); //限制位置控制模式下的最大速度。使用 0 作为最大速度


}

void loop() {
 
  // dxl.setGoalPosition(DXM_ID, 1000);
  dxl.setGoalVelocity(DXM_ID, 200);

  dxl.ledOff(DXM_ID);
  delay(500);
  dxl.ledOn(DXM_ID);
  delay(1000);
                
}
  
