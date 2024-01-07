# Work In Progress
Work in progress

# Rome total war 1.5 scripthook (Version 1.1.0)
A scripting plugin you add to the game to then write scripts in C.
Wait scripts in C? Yes in Goddamn C.

# License
[ISRAEL LICENSE](https://github.com/MuaazH/ISRAEL-LICENSE)
Your only option is to israel the software, i.e. steal it and claim its yours, the US & UK will approve. No one will stop you. 100% legal.
Please Visit: [taxpayersforpeace.org](https://taxpayersforpeace.org)

# HOW TO INSTALL
Copy these files into the main game directory:
```
d3d8.dll                 <- asi loader
libtcc.dll               <- tiny c compiler
scriptHook.asi           <- the plugin
scripts                  <- scripts & sdk
```
(Only works with RomeTW.exe v1.5)<br>

if you get a missing dll error, install VC++2013 form Microsoft

# HOW IT WORKS
1. Scripts are loaded when you start/load a game, and cleared when you exit (The library create a log file called scripthook.log when started)
2. Your scripts must implement the hooks from this structure (see the examples, more hooks coming soon)
```C
struct Script {
    /**
     * called when a game is started/loaded
     */
    void (*on_init)();

    /**
     * called when a game is closed
     */
    void (*on_destroy)();

    /**
     * called at the end of each turn
     */
    void (*on_advance_time)(GameDate *);

    /**
     * called after a city updates it's population stats
     */
    void (*on_city_population_stats)(CityStats *);

    /**
     * called after a city updates it's order stats
     */
    void (*on_city_order_stats)(CityStats *);

    /**
     * called after a city updates it's income stats
     */
    void (*on_city_income_stats)(CityStats *);
};

```
3. See [scripthook.h](scripts/lib/scripthook.h) for API you can call
4. If you create a mod, let me know. I like new ideas (Email in my profile)
5. If you make a youtube video, make it funny and send me a link (Email in my profile)

# Thanks
ASI-Loader: https://github.com/ThirteenAG/Ultimate-ASI-Loader <br>
TinyCC: https://github.com/TinyCC/tinycc/tree/mob <br>

# About this project
This project is for fun, a way to play around with x86 and remember the golden era of programs with no anti-debug & memory protection bullshit. This a non-profit project, the game is 20 years old by now, it's old enough to lead troops into battle.