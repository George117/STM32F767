/**
  @page LwIP_IAP  IAP over Ethernet 
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LwIP/LwIP_IAP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the in-application programming (IAP) over 
  *          Ethernet.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
   @endverbatim

@par Description

This application guides STM32Cube HAL API users to run In-Application Programming 
(IAP) over Ethernet. 

Two IAP options are provided: 
 - IAP using TFTP (Trivial File Transfer Protocol)
 - IAP using HTTP (Hypertext Transfer Protocol) 

User has select through compile options (in main.h file) to include one or both 
options.

LwIP/LwIP_IAP/Binary directory contains an application binary example (STM32756G_EVAL_GPIO_Toggle.bin) 
which can be used to be transfered and executed. It toggles the 4 LEDs successively with a delay of 
100 ms.

User has to reset the device while Pushing TAMPER button to enter IAP mode.

If the LCD is used (#define USE_LCD in main.h), log messages will be displayed 
to inform user about ethernet cable status and the IP address value, else this 
will be ensured by LEDs:
  + LED1: ethernet cable is connected.
  + LED2: ethernet cable is not connected.

If a DHCP server is available, a dynamic IP address can be allocated by enabling 
the DHCP process (#define USE_DHCP in main.h)


The required userID and password are set, and can be modified, in the main.h file

Note: In this application the Ethernet Link ISR need the System tick interrupt 
to configure the Ethernet MAC, so the Ethernet Link interrupt priority must be 
set lower (numerically greater) than the Systick interrupt priority to ensure 
that the System tick increments while executing the Ethernet Link ISR.

Note: By default, the Ethernet Half duplex mode is not supported in the 
STM327x6G_EVAL board, for more information refer to the HAL_ETH_MspInit() 
function in the ethernetif.c file

Note : ETH_MDIO signal is connected to PA2 which is shared with other signals like SAI2_SCKB.
By default on STM327x6G_EVAL board, PA2 is connected to SAI2_SCKB, so to connect PA2 to ETH_MDIO :
    - jumper JP21 must be on the position 2-3

Note : ETH_MDC is connected to PC1 which is shared with other signals like SAI1_SDA.
By default on STM327x6G_EVAL board, PC1 is connected to SAI1_SDA, so to connect PC1 to ETH_MDC :
    - jumper JP22 must be on the position 2-3

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
	  
@note The required userID and password are set, and can be modified, in the main.h file.
      
@note The STM32F7xx devices can reach a maximum clock frequency of 216MHz but as this application uses SDRAM,
      the system clock is limited to 200MHz. Indeed proper functioning of the SDRAM is only guaranteed 
      at a maximum system clock frequency of 200MHz.

For more details about this application, refer to UM1709 "STM32Cube Ethernet IAP application"


@par Keywords

Middleware, IAP, In-Application Programming, Ethernet, ETH, LwIP, TFTP, TCP/IP, HTTP, LCD

@Note�If the user code size exceeds the DTCM-RAM size or starts from internal cacheable memories (SRAM1 and SRAM2),that is shared between several processors,
 �����then it is highly recommended to enable the CPU cache and maintain its coherence at application level.
      In case of constraints it is possible to configure the MPU as "Write through/not shareable" to guarantee the cache coherence at write access but the user
	  has to ensure the cache maintenance at read access though.
������The address and the size of cacheable buffers (shared between CPU and other masters)  must be properly updated to be aligned to cache line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence, but depending on the use case
����� It is also possible to configure the MPU as "Write through", to guarantee the write access coherence.
������In that case, the MPU must be configured as Cacheable/Bufferable/Not Shareable.
������Even though the user must manage the cache coherence for read accesses.
������Please refer to the AN4838 �Managing memory protection unit (MPU) in STM32 MCUs�
������Please refer to the AN4839 �Level 1 cache on STM32F7 Series�

@par Directory contents

    - LwIP/LwIP_IAP/Inc/app_ethernet.h       header of app_ethernet.c file
    - LwIP/LwIP_IAP/Inc/ethernetif.h         header for ethernetif.c file
    - LwIP/LwIP_IAP/Inc/lcd_log_conf.h       LCD Log configuration file
    - LwIP/LwIP_IAP/Inc/main.h               Main program header file          
    - LwIP/LwIP_IAP/Inc/flash_if.h           header for flash_if.c
    - LwIP/LwIP_IAP/Inc/httpserver.h         header for httpserver.c
    - LwIP/LwIP_IAP/Inc/tftpserver.h         header for tftpserver.c
    - LwIP/LwIP_IAP/Inc/lwipopts.h           LwIP stack configuration options
    - LwIP/LwIP_IAP/Inc/fsdata.h             header for fsdata.c  
    - LwIP/LwIP_IAP/Inc/stm32f7xx_hal_conf.h Library Configuration file
    - LwIP/LwIP_IAP/Inc/stm32f7xx_it.h       Interrupt handlers header file    
    - LwIP/LwIP_IAP/Src/app_ethernet.c       Ethernet specific module
    - LwIP/LwIP_IAP/Src/main.c               Main program          
    - LwIP/LwIP_IAP/Src/flash_if.c           high level functions for flash access (erase, write)
    - LwIP/LwIP_IAP/Src/httpserver.c         IAP http server functions
    - LwIP/LwIP_IAP/Src/tftpserver.c         IAP tftpserver functions
    - LwIP/LwIP_IAP/Src/fsdata.c             ROM filesystem data (html pages)
    - LwIP/LwIP_IAP/Src/system_stm32f7xx.c   STM32F7xx system file
    - LwIP/LwIP_IAP/Src/stm32f7xx_it.c       STM32F7xx Interrupt handlers
    - LwIP/LwIP_IAP/Binary                   contains a binary image to be 
                                             loaded with the IAP code 
             
@par Hardware and Software environment  
   
  - This application runs on STM32F756xx/STM32F746xx devices.
    
  - This application has been tested with the following environments:
     - STM327x6G_EVAL board
     - Http clients: Firefox Mozilla (v24) or Microsoft Internet Explorer (v8 and later)
     - TFTP client and DHCP server: PC utility TFTPD32 (http://tftpd32.jounin.net/)
      
  - STM327x6G_EVAL Set-up
    - Connect the eval board to remote PC (through a crossover ethernet cable)
      or to your local network (through a straight ethernet cable)
    - jumper JP21 must be on the position 2-3 (ETH_MDIO signal)
    - jumper JP22 must be on the position 2-3 (ETH_MDC signal)
    - jumper 24 must be on the position 2-3 (LED1 use)
    - jumper 23 must be on teh position 2-3 (LED3 use)
  
  - Remote PC Set-up
    - Configure a static IP address for your remote PC 
      for example 192.168.0.11 


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the application
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
