## tec-8x8x8

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/64-to-512.png)
![image](https://user-images.githubusercontent.com/58069246/192197176-98d637e0-66cb-463e-8f43-c5abc83ef2e8.png)



After the 8x8 comes 8x8x8 by adding more latches. rather than round up all the parts its cheaper to buy a 8x8x8 kit for under $30, https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html and we replace their microcontroller with our tec-1 as controller. The kits use  buffers so all we do is hook into each of the 8 data paths. their schematic https://github.com/SteveJustin1963/tec-8x8x8/blob/master/SKU331661/Schematic/Schematic.pdf
uses an 8052 microcontroller, with three sets of 8 bit ports, p00-p07 goes to each of the eight 573 latches. The enable oc is pull down for always enabled.
then p20 to p27 drive each of the latch's clock lines. this switches on each layer one at a time. last, p10 to p17 finish the cathode side of each layer, via a LN2803 with eight darlingtons sinking current thru 220 ohms. here is the cct.

![image](https://user-images.githubusercontent.com/58069246/193485615-3e63ddc4-8e09-491d-a5ea-04f4ed1a5869.png)




### code
so maybe we can intercept the 3x 8bit busses... p10-17, p00-07 and p20-27 with the undocumented z80 `out(c)` command to drive the 3x busses thus the 3 cube dimensions, the out() opcode used like this allows writing DATA to the both data and address at the same time. we needto control latch enables somehow 

```
out(c),reg
```

We load the a reg then the bc reg, then execute out(c), it will simultaneously output 24 bits, 8 on data and 16 on address at the same time, the code looks like this;
```
ld a,n        ; load a
out (c),bc    ; load bc and execute, now a+bc goes out, for latch to pickup if enabled
```


### cct ideas

Experimental circuit to connect the tec1- to 8x8x8 kit

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/wiring-1.png)

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/schem-1.png)



https://easyeda.com/editor#id=2566f0087f05462c8c1e0b6c8555f6c8|e49368fb5fbd4fbda2a12e08e32c8036

 
 









 

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




