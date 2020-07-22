# arduino-inverter-power-saver
This project turns an inverter on only when the fridge is on to save power in camper vans.
## Motivation
When using an AC refrigerator off-grid, e.g. in a camper van, most of the power that's wasted compared to an equivalent DC fridge comes from idling the AC inverter for long periods of time. This project solves that problem.
## What it does
Every 5 minutes, the Arduino turns the AC inverter on and leaves it on until no AC current to the fridge is detected.
## How it works
Fridges have mechanical thermostats that switch the compressor on/off based on temperature. When the fridge is too warm, the thermostat switch is on and the fridge immediately starts running when the Arduino turns on the inverter. When the fridge is cold enough, the thermostat switch is off and no current flows, so the Arduino turns off the inverter to save power.
## The inverter can still be used as normal
When the relay is connected in parallel with the existing on/off switch in the inverter, the user can still turn the inverter on when they need it. This is fine because the fridge's thermostat is what controls when the fridge runs. In other words, this circuit does not impede normal operation of the inverter. It only prevents the user from being able to turn off the inverter when the fridge is running, which is what you would want anyway.
## Example power savings
If the fridge runs for 10 minutes every hour on average = 4 hours per day, instead of idling the inverter for ~20 hours per day, with this project the inverter will idle for at most 8 seconds every 5 minutes for ~20 hours ~= 240 times per day x 8 seconds ~= 32 minutes per day, which saves ~19.5 hours of inverter idling time. So, for an inverter that draws 1 amp at idle, which is pretty accurate for many inverters, this project saves about 19.5 hours x 1 amp = *19.5 amp-hours* at 12 volts. That is a lot of valuable power when running off batteries and solar!
## Measurements
I measured 60 watts from my standard 1.7 cu ft AC mini fridge when the compressor was running, which is very similar to claims for DC fridges of similar size in Amazon reviews. With this Arduino circuit, I've found that the fridge + inverter uses ~65 amp-hours per day in the summer when temperatures are in the 90's F, which I've found is fully recharged by 2x100 watt solar panels during sunny days. It will use less power when it's cooler outside, because the fridge will run less.
## Choosing an inverter
My inverter is a pure sine inverter. I tested the fridge on a modified sine inverter, and that did not work well. The fridge had to run a lot longer to cool the same amount, and the compressor got much hotter. So I recommend a pure sine inverter.
## A helpful tip
While you have the inverter opened up to solder the two wires to the on/off switch, it's a good idea to remove the piezo beeper with pliers so that it doesn't make any noise. Why manufacturers make inverters noisy is beyond me, it's pretty obvious that there is fault when your power goes out, so there's really no need for any beeping. Maybe there is a government regulation that inverters have to beep? ¯\\_(ツ)_/¯

~ Drew
