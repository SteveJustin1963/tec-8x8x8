## tec-8x8x8
![image](https://user-images.githubusercontent.com/58069246/193498963-cf5ad5fe-289f-4f17-93af-3003e1cf7d9b.png)


To upgrade from the 8x8 LED cube to the 8x8x8 version, rather than purchasing all the individual parts, it is more cost-effective to purchase a 8x8x8 LED cube kit for under $30. One example of such a kit can be found at the provided link, which is a Geekcreit 8x8x8 LED Cube kit. Instead of using the microcontroller provided in the kit, we can replace it with our TEC-1 as the controller. The kit already includes buffers, so all we have to do is connect the TEC-1 to each of the 8 data paths.

![image](https://user-images.githubusercontent.com/58069246/193499278-2d37c93b-46a5-4451-88d4-2cc323aaa395.png)
![image](https://user-images.githubusercontent.com/58069246/193499237-778af94a-1878-4c2e-9840-2c60b31d8919.png)
![image](https://user-images.githubusercontent.com/58069246/193499163-0824486f-7264-4b04-9bf4-73e1a209d771.png)
![image](https://user-images.githubusercontent.com/58069246/193499044-3a7a1f15-19d4-4840-9161-3d60a4750e75.png)
![image](https://user-images.githubusercontent.com/58069246/193485615-3e63ddc4-8e09-491d-a5ea-04f4ed1a5869.png)

The schematic for the 8x8x8 LED cube can be found on the provided link on GitHub, which uses an 8052 microcontroller. It has three sets of 8-bit ports, with p00-p07 connected to each of the eight 573 latches. The enable pin, labeled as OC, is pulled down for always-enabled. The p20-p27 ports drive each of the latch's clock lines, which switch on each layer one at a time. Finally, p10-p17 are connected to the cathode side of each layer through a LN2803 with eight Darlingtons sinking current through 220 ohms. The 74573's pin 1, labeled as /OE or /OC, is set to low, which means it is always on. Then the data is clocked in through pin 11 from the controller's ports p20-27.


## ver2 
To control the latch enables, we can add three 273 latches and a driver circuit connected to ports 3, 4, and 5. This will allow us to use the out(c) command to drive the three dimensions of the cube and control the latch enables using the additional latches and driver circuit connected to ports 3, 4, and 5. This will be a simple addition to the circuit.

https://easyeda.com/editor#id=d92d445978864fd6a0b9c903333f8f80|1cce039453314ed0890fe77e2147df22


## ver1
It is possible to intercept the three 8-bit busses, p10-17, p00-07, and p20-27, with the undocumented Z80 "out(c)" command to drive the three dimensions of the cube. The out() opcode can be used in this way to write data to both the data and address lines simultaneously. However, to control the latch enables, further investigation would be needed to determine the appropriate method. It could be done by manipulating the enable pin on the 74573 or by utilizing a different command or circuit.

```
out(c),reg
```

We load the a reg then the bc reg, then execute out(c), it will simultaneously output 24 bits, 8 on data and 16 on address at the same time, the code looks like this;
```
ld a,n        ; load a
out (c),bc    ; load bc and execute, now a+bc goes out, for latch to pickup if enabled (how?).

```

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/wiring-1.png)

https://easyeda.com/editor#id=2566f0087f05462c8c1e0b6c8555f6c8|e49368fb5fbd4fbda2a12e08e32c8036

wont work ?







