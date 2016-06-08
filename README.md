# JVF2010-A-Controller
Software and notes to control a JVF 2010 A sign via the internal 34 pin ribbon cable. This replaces the internal 386 computer and floppy and sends data direct to the internal logic. 

So here is the plan, Vancouver Hack Space has a JVF 2010A LED sign. Its curently driven by a 386 PC with a floppy drive and no internal storage. The goal is to replace the 386 with something a little more modern and WiFI-y. 

The floppy drive and DOS program is well documented: http://mainisusuallyafunction.blogspot.ca/2010/10/programming-jvf-2010.html

As is doing an end run of the internal logic board and driving the shift registers directly: https://www.noisebridge.net/wiki/Big_LED_Screen

My goal is to emulate the 386 software using an arduino mega, and drive the internal logic board directly. 
