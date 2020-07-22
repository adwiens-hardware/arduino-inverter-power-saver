# arduino-inverter-power-saver
This project turns an inverter on/off based on the temperature of an AC mini fridge to save power in camper vans.
## Motivation
When using an AC fridge in a camper van, most of the power that's wasted compared to using an equivalent DC fridge comes from idling the AC inverter for long periods of time. This project solves that problem.
## What it does
Every 5 minutes, the Arduino turns on the inverter for 8 seconds and leaves it on until no AC current is detected.
## How it works
Fridges have mechanical thermostats that switch the compressor on/off based on temperature, so when the fridge is off no current flows.
## The inverter can still be used as normal
When the relay is connected in parallel with the existing on/off switch in the inverter, the user can still turn the inverter on when they need it. This is fine because the fridge's thermostat is what controls when the fridge runs. In other words, this circuit does not impede normal operation of the inverter.
## Example power savings
If the fridge runs for 10 minutes every hour on average = 4 hours per day, instead of idling the inverter for ~20 hours per day, with this project the inverter will idle for at most 8 seconds every 5 minutes for ~20 hours ~= 240 times per day x 8 seconds ~= 32 minutes per day, which saves ~19.5 hours of inverter idling time. So, for an inverter that draws 1 amp at idle, which is pretty accurate for many inverters, this project saves about 19.5 hours x 1 amp = *19.5 amp-hours* at 12 volts. That is a lot of valuable power when running off batteries and solar!
