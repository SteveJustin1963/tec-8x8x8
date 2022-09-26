## tec-8x8x8

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/64-to-512.png)

![image](https://user-images.githubusercontent.com/58069246/192197176-98d637e0-66cb-463e-8f43-c5abc83ef2e8.png)



after the 8x8 comes the 8x8x8 by adding more latches. rather than round up all the parts its cheaper to buy a 8x8x8 kit for under $30, and we replace their microcontroller with our tec-1 as a c controller. 

kits example... https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html

code...i want to use the know but undocumented z80 `out(c)` command to drive the 3 x 8bit dimensions of the cube,


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
 







### 8x8x8 Kit info

https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/8x8x8-LED-Cube-Image-Circuit-Diagram-Full-Size.png


Notes from the kit website...

Instruction: Click to open (Instruction is for reference only, will have some changes with the actual product, such as change SMD to DIP.)
Note: This is a DIY kit, you need to have some knowledge of electronics and ability.
Needs a lot of soldering, you should have enough patience.
S2, S3 is the reserved position, there is no actual use, the package is not included.

Features:

You can use it to achieve the Dynamic 3D effect:
1. Pyramid
2. Rain graphic effect
3. Leaping graphics effect
4. Rotating graphic effect
5. Square move effect
6. Square light move effect
7. Lamp standard rollover effect
8. Square magnify and shrink effect
9. Reverse lamp
10. Triangle three-dimensional graphics rotation effect
11. Article lamp running effect
12. Pull screen graphics effect
13. Fast and slow display

Specification:

Light Color: Blue
PCB Size: 11.1 x 12.7cm
Power Supply Voltage: 4.5~5.5V
Net weight: About 240g

Package list:

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/C89439F9BE3E6986B18FDAB69E885086.jpg.webp)

 

## Iterate

make more led effects
- read photoresistor via schmitt or ADC and input into the mixing table, use hand to control light 
- induce feedback loops, chaos cct etc
- superposition code behavior thru mixing matrix
- 3d tetris
- use 5 https://github.com/SteveJustin1963/tec-EYE set into a cube, then feed this into the outer 5 layers of the 8x8x8 cube, etc
- or anthing like this eg x + y + z. 
- In other projects this could be xy coils and luminance in a crt tube, or xy stepper motor + laser, or xyz robot arm, or telescope control, ...




 ## Ref

- https://www.instructables.com/Led-Cube-8x8x8/
- https://www.keil.com/dd/docs/c51/reg52.h
- https://www.keil.com/support/man/docs/c51/c51_intrins_h.htm



