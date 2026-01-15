# superkvm_usb_fw_dev
The user development project of the superkvm usb series products

## Introduction
superkvm usb series 产品的二次开发参考工程

所有的工程都基于 stmcubemx 生成，仅为了适配硬件作必要的简单修改，只包含核心框架，不包含任何 kvm 的具体实现。

官方保证这些例子都可以在superkvm usb系列产品上正常运行，能正常循环打印日志。

## 硬件 mcu
stm32f405rg

## ide
keil 5.42.0.0

## download
only support through superkmv’s web ota tools：webapp.superkvm.com

## 01
一个包含HS cdc 和 FS hid的 双 usb device模式设备用例