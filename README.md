## tec-8x8x8

We have the 8x8, and on much the same design we can go 8x8x8 by adding more latches and another 138 chip. We can also blast all data to the cube using the undocumented out (c) command

```
out (c),a
out (a0-a7 b),a  ; so ‘a’ goes to a0-7 and ‘a’ goes to a8-15

The one we want is

out (c), reg
```

We preload bc, and a then hit out, then it dumps on all three registers at same time; hence

```
ld a,n
out (c),bc [reg pair]
out (a0-7),a  ; a >a0-7 + bc>a0-15 
```


out() op code that allows writing data to both the data and address bus!
so you have 3 registers to make io with in one go.

let use this feature to drive a 8x8x8 cube of leds


rather than using  the existing all 2x 8 latch ports from LED's and SPK plus plus add 1 extra 8 port latch 
* or use special OUT commands to put data of 3x bytes on data and address buses, address bus will act as data output
* code in asm and forth 



### circuit using 273 latches

https://easyeda.com/editor#id=e46b6deb1e7e4ed88163b204ffa0233f|a7698e020e1d46d7ba73e56e72c2b4c2|d16a76b684a24d72a65f856c23ff9f3b

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/888-3.png)
![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/Photo%20View_2021-07-22%20(1).svg)
![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/Photo%20View_2021-07-22%20(2).svg)
![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/Schematic_tec-8x8x8-3_2021-07-22.svg)

 


### circuit using 574 latches

https://easyeda.com/editor#id=e46b6deb1e7e4ed88163b204ffa0233f|584f4ef8dc4f4d8a86f2fa95dd8c9a31|e470737c89ea43de9b499520191f4aee

![](https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/888-4.png)

 unfinished

## Ref
kit
https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html?utm_source=google&utm_medium=cpc_ods&utm_content=2ysq&utm_campaign=2ysq-all-Sds-Feed-0726&ad_id=535762987585&gclid=CjwKCAiA7dKMBhBCEiwAO_crFER4mDiaziBiiCnnRuP5qEFwkr5mdtMtPl1ukUHsAz27irctyFSUdBoC1qEQAvD_BwE&cur_warehouse=CN


