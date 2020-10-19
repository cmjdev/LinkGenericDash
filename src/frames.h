#include <Arduino.h>

struct s_frame
{
    const float mult;
    const short add;
    const char *id;
    const byte prec;
};

struct s_frame frame[13][3] = {
    {{1, 0, "GLOBALS.RPM.", 0}, {1, 0, "GLOBALS.MAP.", 0}, {1, -100, "GLOBALS.MGP.", 0}},
    {{0.1, 0, "GLOBALS.BARO.", 0}, {0.1, 0, "GLOBALS.TPS.", 0}, {0.1, 0, "GLOBALS.IDC.", 0}},
    {{1, 0, "GLOBALS.IDC2.", 0}, {0.001, 0, "GLOBALS.IPW.", 0}, {1, -50, "GLOBALS.ECT.", 0}},
    {{1, -50, "GLOBALS.IAT.", 0}, {0.01, 0, "GLOBALS.BAT.", 0}, {0.1, 0, "GLOBALS.MAF.", 0}},
    {{1, 0, "GLOBALS.GEAR.", 0}, {1, 0, "GLOBALS.INJT.", 0}, {0.1, -100, "GLOBALS.IGNT.", 0}},
    {{0.1, 0, "GLOBALS.INCAML.", 0}, {0.1, 0, "GLOBALS.INCAMR.", 0}, {-0.1, 0, "GLOBALS.EXCAML.", 0}},
    {{-0.1, 0, "GLOBALS.EXCAMR.", 0}, {0.001, 0, "GLOBALS.LAMBD1.", 0}, {0.001, 0, "GLOBALS.LAMBD2.", 0}},
    {{1, 0, "GLOBALS.TRIGER.", 0}, {1, 0, "GLOBALS.FAULTS.", 0}, {1, 0, "GLOBALS.FUELP.", 0}},
    {{1, -50, "GLOBALS.OILT.", 0}, {1, 0, "GLOBALS.OILP.", 0}, {0.1, 0, "GLOBALS.LFSPD.", 0}},
    {{0.1, 0, "GLOBALS.LRSPD.", 0}, {0.1, 0, "GLOBALS.RFSPD.", 0}, {0.1, 0, "GLOBALS.RRSPD.", 0}},
    {{5, 0, "GLOBALS.KNK1.", 0}, {5, 0, "GLOBALS.KNK2.", 0}, {5, 0, "GLOBALS.KNK3.", 0}},
    {{5, 0, "GLOBALS.KNK4.", 0}, {5, 0, "GLOBALS.KNK5.", 0}, {5, 0, "GLOBALS.KNK6.", 0}},
    {{5, 0, "GLOBALS.KNK7.", 0}, {5, 0, "GLOBALS.KNK8.", 0}, {1, 0, "GLOBALS.LIMITS.", 0}},
};