#!/usr/bin/env python  
# -*- coding: utf-8 -*-  
import requests  
import json  
import time  
  
def main():  
    fileRecord = open("result.txt", "w")  
    fileRecord.write("connect to yeelink\n");  
    fileRecord.close()  
    while True:  
        # 打开文件  
        file = open("/home/pi/temp")  
        # 读取结果，并转换为浮点数  
        temp = float(file.read()) / 1000
        # 关闭文件  
        file.close()  
        # 设备URI  
        apiurl = 'http://api.yeelink.net/v1.0/device/19**58/sensor/34647/datapoints'  
        # 用户密码, 指定上传编码为JSON格式  
        apiheaders = {'U-ApiKey': '10e3db583be98eb248c30cfa5bdb62bd', 'content-type': 'application/json'}  
        # 字典类型数据，在post过程中被json.dumps转换为JSON格式字符串 {"value": 48.123}  
        payload = {'value': temp}  
        #发送请求  
        r = requests.post(apiurl, headers=apiheaders, data=json.dumps(payload))  
        # 向控制台打印结果  
        fileRecord = open("result.txt", "a")  
        strTime = time.strftime('%Y-%m-%d:%H-%M-%S',time.localtime(time.time()))  
        fileRecord.writelines(strTime + "\n")  
        strTemp = "temp : %.1f" %temp + "\n"  
        fileRecord.writelines(strTemp)  
        fileRecord.writelines(str(r.status_code) + "\n")  
        fileRecord.close()  
          
        time.sleep(2)  
  
if __name__ == '__main__':  
    main()  
      