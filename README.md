# QUno Archives

This repository contains historical implementations of an Uno-like card game.

## Developer Notes

This code is being published for archival purposes only. No 
pull requests will be merged.

## History

I started building applications to play an Uno-like card game circa 1996, 
so my sister Olivia could play even though I was in college or elsewhere in 
the world.

* *Version 1, circa 1996* This version targeted Microsoft Windows 3.1 and was 
built with Microsoft Visual C++ 1.52c. It also didn't really work, because it 
would usually leak GDI resources and exhaust the system before you could finish a game.
* *Version 2, circa 1997* This version targeted Microsoft Windows 95 and was
built with Microsoft Visual C++ 2.0. It worked a lot a better, but would still 
leak memory and usually die after a few games.
* *Version 3, circa 1999* This version targeted Windows 2000 and was built with 
Microsoft Visual C++ 6.0. It was a brand-new architecture, based on COM and mostly
implemented via ATL. The game engine was finished (even including a VBScript-based 
test harness) but the UI was never completed. However the concept of separating 
the game engine from the UI was born here and remains to this day.
