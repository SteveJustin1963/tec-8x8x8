## tec-8x8x8

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/64-to-512.png)
![image](https://user-images.githubusercontent.com/58069246/192197176-98d637e0-66cb-463e-8f43-c5abc83ef2e8.png)



After the 8x8 comes 8x8x8 by adding more latches. rather than round up all the parts its cheaper to buy a 8x8x8 kit for under $30, https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html and we replace their microcontroller with our tec-1 as controller. the kits uses  buffers so all we do is hook into each of the 8 data paths. their schematic https://github.com/SteveJustin1963/tec-8x8x8/blob/master/SKU331661/Schematic/Schematic.pdf
uses 8052 microcontroller, with three sets of 8 bit ports, p00-p07 goes to each of the eight 573 latches. the enable oc is pull down for always enabled.
then p20 to p27 drive each of latches clock lines. this switches on each layer one at a time. last, p10 to p17 finish the cathode side of each layer, via a LN2803 with eight darlingtons sinking current thru 220 ohms.



### code
i want to use the know but undocumented z80 `out(c)` command to drive the 3 x 8bit dimensions of the cube,


So using out() opcode like this allows writing to the BOTH data and address at the same time! 
The latches need to be enabled at right time to pickup the data, then we transfer this to the 8x8x8 kit. 

```
out(c),reg
```

We load the a reg then the bc reg, then execute out(c), it will simultaneously output 24 bits, 8 on data and 16 on address at the same time, the code looks like this;
```
ld a,n        ; load a
out (c),bc    ; load bc and execute, now a+bc goes out, for latch to pickup if enabled
```

### ver 2
36.9.22
rewire 40 pins from tec-1 side to a 40pin idc on 888 side



### ver 1

Experimental circuit to connect the tec1- to 8x8x8 kit

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/wiring-1.png)

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/schem-1.png)



https://easyeda.com/editor#id=2566f0087f05462c8c1e0b6c8555f6c8|e49368fb5fbd4fbda2a12e08e32c8036

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/pcb.png)
 









 

## Iterate
- more led effects
- read photoresistor via schmitt or ADC and input into the mixing table, use hand to control light 
- induce feedback loops, chaos cct etc
- superposition code behavior thru mixing matrix
- 3d tetris
- use 5 https://github.com/SteveJustin1963/tec-EYE set into a cube, then feed this into the outer 5 layers of the 8x8x8 cube, etc
- or anthing like this eg x + y + z. 
- In other projects this could be xy coils and luminance in a crt tube, or xy stepper motor + laser, or xyz robot arm, or telescope control, ...




 ### Ref

- https://www.instructables.com/Led-Cube-8x8x8/
- https://www.keil.com/dd/docs/c51/reg52.h
- https://www.keil.com/support/man/docs/c51/c51_intrins_h.htm



