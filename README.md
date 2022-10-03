## tec-8x8x8
![image](https://user-images.githubusercontent.com/58069246/193498963-cf5ad5fe-289f-4f17-93af-3003e1cf7d9b.png)



After the 8x8 comes 8x8x8 by adding more latches. rather than round up all the parts its cheaper to buy a 8x8x8 kit for under $30, https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html and we replace their microcontroller with our tec-1 as controller. The kits use  buffers so all we do is hook into each of the 8 data paths. 

![image](https://user-images.githubusercontent.com/58069246/193499278-2d37c93b-46a5-4451-88d4-2cc323aaa395.png)
![image](https://user-images.githubusercontent.com/58069246/193499237-778af94a-1878-4c2e-9840-2c60b31d8919.png)
![image](https://user-images.githubusercontent.com/58069246/193499163-0824486f-7264-4b04-9bf4-73e1a209d771.png)
![image](https://user-images.githubusercontent.com/58069246/193499044-3a7a1f15-19d4-4840-9161-3d60a4750e75.png)
![image](https://user-images.githubusercontent.com/58069246/193485615-3e63ddc4-8e09-491d-a5ea-04f4ed1a5869.png)

their schematic https://github.com/SteveJustin1963/tec-8x8x8/blob/master/SKU331661/Schematic/Schematic.pdf
uses an 8052 microcontroller, with three sets of 8 bit ports, p00-p07 goes to each of the eight 573 latches. The enable oc is pull down for always enabled.
then p20 to p27 drive each of the latch's clock lines. this switches on each layer one at a time. last, p10 to p17 finish the cathode side of each layer, via a LN2803 with eight darlingtons sinking current thru 220 ohms.  the 74573 pin 1 /oe aka /oc are all low = on, then the data is clocked pin 11 from controller port p20-27.


### ver2 
stuff that. add another 273 latch and strobe off port3 - Y3 etc from the 138 on tec1. better. 



### ver1
so maybe we can intercept the 3x 8 bit busses... p10-17, p00-07 and p20-27 with the undocumented z80 `out(c)` command to drive the 3x busses thus the 3 cube dimensions, the out() opcode used like this allows writing DATA to the both data and address at the same time. but how to control latch enables ? 

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

wont work


## Iterate
- more led effects
- read photoresistor via schmitt or ADC and input into the mixing table, use hand to control light 
- induce feedback loops, chaos cct etc
- superposition code behavior thru mixing matrix
- 3d tetris
- use 5 https://github.com/SteveJustin1963/tec-EYE set into a cube, then feed this into the outer 5 layers of the 8x8x8 cube, etc
- or anything like this eg x + y + z. 
- In other projects this could be xy coils and luminance in a crt tube, or xy stepper motor + laser, or xyz robot arm, or telescope control, ...




 ### Ref

- https://www.instructables.com/Led-Cube-8x8x8/
- https://www.keil.com/dd/docs/c51/reg52.h
- https://www.keil.com/support/man/docs/c51/c51_intrins_h.htm





