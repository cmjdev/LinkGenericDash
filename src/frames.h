#include <Arduino.h>

struct s_frame
{
    const float mult;
    const short add;
    const char *id;
    const byte prec;
};

struct s_frame frame[13][3] = {
    {{1, 0, "RPM", 0}, {1, 0, "MAP", 0}, {1, -100, "MGP", 0}},
    {{0.1, 0, "BARO", 0}, {0.1, 0, "TPS", 0}, {0.1, 0, "IDC", 0}},
    {{1, 0, "IDC2", 0}, {0.001, 0, "IPW", 0}, {1, -50, "ECT", 0}},
    {{1, -50, "IAT", 0}, {0.01, 0, "BAT", 2}, {0.1, 0, "MAF", 0}},
    {{1, 0, "GEAR", 0}, {1, 0, "INJT", 0}, {0.1, -100, "IGNT", 0}},
    {{0.1, 0, "INCAML", 0}, {0.1, 0, "INCAMR", 0}, {-0.1, 0, "EXCAML", 0}},
    {{-0.1, 0, "EXCAMR", 0}, {0.001, 0, "LAMBD1", 0}, {0.001, 0, "LAMBD2", 0}},
    {{1, 0, "TRIGER", 0}, {1, 0, "FAULTS", 0}, {1, 0, "FUELP", 0}},
    {{1, -50, "OILT", 0}, {1, 0, "OILP", 0}, {0.1, 0, "LFSPD", 0}},
    {{0.1, 0, "LRSPD", 0}, {0.1, 0, "RFSPD", 0}, {0.1, 0, "RRSPD", 0}},
    {{5, 0, "KNK1", 0}, {5, 0, "KNK2", 0}, {5, 0, "KNK3", 0}},
    {{5, 0, "KNK4", 0}, {5, 0, "KNK5", 0}, {5, 0, "KNK6", 0}},
    {{5, 0, "KNK7", 0}, {5, 0, "KNK8", 0}, {1, 0, "LIMITS", 0}},
};