#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define CORGI_WIDTH 69
#define CORGI_HEIGHT 23
#define SPRITE_COUNT 16
#define CORGI_SPEED 3

int maxx;
int maxy;

int x;
int y;
char** data;

int current_index = 0;

void initialize_corgis();
void draw_corgi(int index);

int update() {
  erase();
  draw_corgi(current_index);
  refresh();
  x += CORGI_SPEED;

  current_index++;
  current_index = current_index % SPRITE_COUNT;
  /* y++;*/
}

void draw_corgi(int index) {
  int real_index = index * CORGI_HEIGHT;
  int i;
  int j;
  for (i = 0; i < CORGI_HEIGHT; i++) {
    for (j = 0; j < CORGI_WIDTH; j++) {
      int line = real_index + i;
      if (0 < (x + j) && (x + j) < maxx) {
        move(i + y, x + j);
        addch(data[line][j]);
      }
    }
  }

}

int main() {
  // TODO: Trap Signals
  /* signal(SIGINT, SIG_IGN);*/
  /* signal(SIGTERM, SIG_IGN);*/
  /* signal(SIGABRT, SIG_IGN);*/
  /* signal(SIGTSTP, SIG_IGN);*/
  data = malloc(sizeof(char*) * CORGI_HEIGHT * SPRITE_COUNT * CORGI_WIDTH);
  initialize_corgis();

  // Set up Screen
  WINDOW* window = initscr();
  noecho();

  getmaxyx(window, maxy, maxx);

  // Initialize X and Y
  x = -CORGI_WIDTH;
  y = (maxy / 2) - (CORGI_HEIGHT / 2);

  char* message;
  asprintf(&message, "%d %d", maxx, maxy);
  // TODO Free

  /* printw(data[0]);*/

  while (x < maxx) {
    update();
    usleep(40000);
  }
  endwin();
}

void initialize_corgis() {
  data[0] = "                                                                     ";
  data[1] = "                                                                     ";
  data[2] = "                                             .....          ....     ";
  data[3] = "                                           .... ;,...    .... ...    ";
  data[4] = "                                          ...... :   ....... ;d:.    ";
  data[5] = "                                        .. .,.;k:   . ,;;,  .cO;.    ";
  data[6] = "                     ..........       ......;,;lccc;:loooooc c:.     ";
  data[7] = "                    ............. ... .. ,,,;;coooooooxkxooxk;.      ";
  data[8] = "                  .... ,,,;;;;. ..... .. ;;;:cloooooo; dkookd..      ";
  data[9] = "                  ...,::;:cc:;....,,. .. ;:loodk0000kc :dk00xl,.     ";
  data[10] = "                ....;:cllloolc;, ,;:; .. ;looxKWMMMMWXXXXWMMMMK:.    ";
  data[11] = "                . .,:lloooooooll:;loooc;,cooo0MMWWMMMMMMMMMk,,kl.    ";
  data[12] = "                ...,looooooooooolloooooolllooOWMWXOdxkOKNNN0o:;,.    ";
  data[13] = "                  .,oooooooooooooooooooooooooxXMMM0lc:  ::::: .      ";
  data[14] = "                  .,ooooooooooooooooooooooooodkXMMMMW0dc......       ";
  data[15] = "                  .,oooooooldxoooooooooooooooooOWMMMMMMWc ..         ";
  data[16] = "               ... oOxdoooc.:O0000Okdddooooooolcd0NNWMW0:  .         ";
  data[17] = "              .,dkKMWOl;  ... ::ldxxkKKKk::looddxxlclOk ....         ";
  data[18] = "              ..l0XMO,..        .... ::cl  :xxOKNMOllc ...           ";
  data[19] = "               .. ;: .              ....... ;;:lkXWMK:.              ";
  data[20] = "                                              ...,::,.               ";
  data[21] = "                                                                     ";
  data[22] = "                                                                     ";
  data[23] = "                                                                     ";
  data[24] = "                                                                     ";
  data[25] = "                                               ...                   ";
  data[26] = "                                             ... ,...      .. ...    ";
  data[27] = "                                           .....;o, .    ... ;;..    ";
  data[28] = "                                          .... :,;  ...  . .;,oc.    ";
  data[29] = "                     ...............    .. .,.;d:;;.,clloc;;.cx .    ";
  data[30] = "                   .....  ,,,, ... .. ..... ;;;;coooooooooooc; .     ";
  data[31] = "                  ... ;cllll:... , ..  ..,,;::loooooocckkookk .      ";
  data[32] = "                  .. :clooooc  ;;;;,. .. ;;cooooooooo  :xoox; .      ";
  data[33] = "                ....;clloooolc;;:lc;. . ,;clodk0XXKK0xldkO0K0ko,.    ";
  data[34] = "                . .,cooooooooolllool;.. :loooOWMMMMMMMMMMMMKkkKl.    ";
  data[35] = "                ...;looooooooooooooooo::looooOWMWXXNWNXMMMMk, c:.    ";
  data[36] = "                  . oooooooooooooooooollooooodKMMXd:codONNNNKd .     ";
  data[37] = "              ..;::dOdooooooooooooooooooooooooxKWMKkxdllc,;;; .      ";
  data[38] = "              ..dKNMNOdoooocck0kxooolllooooooood0MMMMMMK;.           ";
  data[39] = "               .. :dkxl:;; .c0XNXK0x: :oooooooldKMMMMMWc. ...        ";
  data[40] = "                  ...........,:cod0Xo;:x00OkkkccKNNNKxc,cocc .       ";
  data[41] = "                              .... :::.:NMMWXk .,::: ...    ..       ";
  data[42] = "                                  ..... cxXNN0; .....  ......        ";
  data[43] = "                                        ..,:::,.                     ";
  data[44] = "                                                                     ";
  data[45] = "                                                                     ";
  data[46] = "                                                                     ";
  data[47] = "                                                                     ";
  data[48] = "                                                                     ";
  data[49] = "                                          ......            ....     ";
  data[50] = "                                         ... ;;..        .....,..    ";
  data[51] = "                          .........      .....;;........... ,;c..    ";
  data[52] = "                      ............  ..... .. :k: ... ,;;, , :0d..    ";
  data[53] = "                    ... ,;::;;,.......  . . .;lccccllooooc; co,.     ";
  data[54] = "                   ...;cllool:...,, . ..  .,;coooooooxkxoxkk;.       ";
  data[55] = "                   ..,cooooooc:cc:;.... ;;:ccloooooo::O0o0WO .       ";
  data[56] = "                   ..:loooooollool:... ,;cloodxkkxdo;.cxx0Kd; .      ";
  data[57] = "               .. ,..cooooooooooool .,,;looxOKWMMWXXXXXXWMMMMK:.     ";
  data[58] = "              . dk0d:clooooooccooooc;;;cooo0MMMWWMMMMMMMMk,,,kl.     ";
  data[59] = "              . ::kMNOdoooooo;;ooooooolloookXNMWKKWMKKMMMOlc:c,.     ";
  data[60] = "               ...,:oxkkdddl:,cooooooooooooddOWMNkllc:ldddddc .      ";
  data[61] = "                    ..,; ;;,:kXK0dloooooooooodKMMWXKOc.......        ";
  data[62] = "                       .....:OWMOlooooooollddkXMMMWNNc.              ";
  data[63] = "                            . ;;l0K000Okl:dO0KNNNNkoc .              ";
  data[64] = "                              . :NMMWXkc,cxxxO0d:::: .               ";
  data[65] = "                              . ;KWMx . .    ,;.. lkx,.              ";
  data[66] = "                              ...,::,..         ..  ,..              ";
  data[67] = "                                                                     ";
  data[68] = "                                                                     ";
  data[69] = "                                                                     ";
  data[70] = "                                                                     ";
  data[71] = "                                                                     ";
  data[72] = "                                       ... ....        ........      ";
  data[73] = "                                       ..;l: ,..      ......,,..     ";
  data[74] = "                                       .. ,cc: .....  ..,,,;c,..     ";
  data[75] = "                     .............. ... ..;dd:;;,cllloc;.;kxl .      ";
  data[76] = "                   .... ,,,;;,... .......,;;;cooooooooooc;; .        ";
  data[77] = "                  .. ;clllc;.. , ..... ,,,loooooocclkkokk  .         ";
  data[78] = "                ....:loooooc  ;;; ... ,;:looooooo   :xox:  .         ";
  data[79] = "                . .;looooool;;clc;.. ;;:ldk0KKX0OdlldOKX0kko,.       ";
  data[80] = "                . .coooooooolloool; ,;;loOWMMMMMMMMMMMMKkkkKl.       ";
  data[81] = "                . .:looooooolloooool:;cooOWMMWXXWXNMMMMk,  c:.       ";
  data[82] = "                . .;cooooooolclooooolclooxXMMMXdcoddONNNKd: .        ";
  data[83] = "                ... ;clooooool:,:looooooodONMMMKll:. ,;;; ..         ";
  data[84] = "                  .. dkxddddol;..,:looooooxXMMMMWNxc .               ";
  data[85] = "                  ..dNWNNNKd;;,  ;:loooodkKWMMMMMWl .                ";
  data[86] = "                  ..dXNKko,,l0KOkdoooooodOXNNNNKxl ..                ";
  data[87] = "                   . ::. ..:NMMMNk:,,     ,:::: ..                   ";
  data[88] = "                    ....... :::::;..... .;:lo  .                     ";
  data[89] = "                                       ..  ,;..                      ";
  data[90] = "                                                                     ";
  data[91] = "                                                                     ";
  data[92] = "                                                                     ";
  data[93] = "                                                                     ";
  data[94] = "                                                                     ";
  data[95] = "                                    ...    ...       ........        ";
  data[96] = "                                    . .,  ::,............  . .       ";
  data[97] = "                                    . ...co;. .. ,;;;,. ;ccl .       ";
  data[98] = "                      .........    .. .  ;lc;cc:loooooc :ddl .       ";
  data[99] = "                   ............  ....  .,coooooooxkkxoxk; ..         ";
  data[100] = "                .... ;:::;;; .......,;;;cloooooo; dKkokd..           ";
  data[101] = "                . .,:loool:;..  ... ;;:lodk000kd: cxk00xl,..         ";
  data[102] = "               ... :loooool; ,;;,.. :lloxKWMMMWXXXXNWMMMMKk:.        ";
  data[103] = "               ..;:looooooolclllc..,cooo0MMWNWMMMMMMMMk,,kMl.        ";
  data[104] = "               ..;cooooooooooooooc:cloookNMWNXOxkOKNNN0o:;:,.        ";
  data[105] = "               ..;cooooooooolloooooooooodONMMMk,,  ::::: .           ";
  data[106] = "               ...,loooooooollcclooooooooxXMMMWXklcc. ...            ";
  data[107] = "                ... :lodddddoo;.;doloooolkWMMMMMMW0d;.               ";
  data[108] = "                  ...;xKNNNX0o..cl,;clloll0MMMMMMWl .                ";
  data[109] = "                    .,kNMMMKd;....;dkkxdd:dNNNNKxl ..                ";
  data[110] = "                    ..c0NWMl lc:.,0WMMN0l. :::: ..                   ";
  data[111] = "                     ..,;:;..;co,,dkkkko,.......                     ";
  data[112] = "                          .........    ...                           ";
  data[113] = "                                                                     ";
  data[114] = "                                                                     ";
  data[115] = "                                                                     ";
  data[116] = "                                                                     ";
  data[117] = "                                      ......          .......        ";
  data[118] = "                                      ..,, . .......... ; ....       ";
  data[119] = "                                      ....:;  .....,,. ; ;::..       ";
  data[120] = "                                    .. ..;d:.;;,cllooc;.;xdl .       ";
  data[121] = "                                  ......,;;coooooooooooc; ..         ";
  data[122] = "                    ........ .......,;;,,loooooocckKkokk .           ";
  data[123] = "                  ........... ..  .,;;;cldxkkkxd;.ckxx0d; ..         ";
  data[124] = "                .....,;;;;;,... .. ;;;codONMMMNK0000KNMMM0l,.        ";
  data[125] = "              ..... ;::clllc, ,;,..;:lloOWMMMMMMMMMMMMKkkKMl.        ";
  data[126] = "              .. ,;clllooooolc;;cc;,:ooo0MMWNXXWNNMMMMk, ck:.        ";
  data[127] = "              ..,;cooooooooooollloolclloxKWMMNOdl:lddddoc ..         ";
  data[128] = "              ..;;coooooooooooooooooooooodONMMMWkc::,. ..            ";
  data[129] = "              ..,;coooooolllloooooooooooood0MMMMMWNNXc.              ";
  data[130] = "               ..;;cloooooolccloooooooooooox0XMMMMWN0;.              ";
  data[131] = "              .... ,;clloddkOcc00Oxddoc:loolloxXMWKk;.               ";
  data[132] = "              .. .....ckOKN0k;,dOXXXK0ko:lO000:ckl; ..               ";
  data[133] = "              ..loo   ,O0NMO  .. ::cllll :NMMMl....                  ";
  data[134] = "              . dkO: ..;coxk;.  .....    .cxkk:..                    ";
  data[135] = "              ..  ,..  .......           ......                      ";
  data[136] = "                                                                     ";
  data[137] = "                                                                     ";
  data[138] = "                                                                     ";
  data[139] = "                                       ...                           ";
  data[140] = "                                    ... ;, ...       ...   ..        ";
  data[141] = "                                    . .  ::;;,........ :::c..        ";
  data[142] = "                                    . . .od; ;.....  .;:;xNc.        ";
  data[143] = "                                    . . .;d:.;:;cllooc;.cKk:.        ";
  data[144] = "                                  ...  .,;;coooooxkkxoxdc ..         ";
  data[145] = "                  .................. ,,;;loooooo; dKkokd..           ";
  data[146] = "               .....  ,,,, ..... .. ;;;cldxkkkkkdox000K0ko:,.        ";
  data[147] = "              .....,;;;;;;;.... ... ;;codONMMMMMMMMMMMMMMMMl.        ";
  data[148] = "             ... ,;;;clllll:, ,;,.. ;;coOWMMMMMMMMMMMMk,,kMl.        ";
  data[149] = "             ..,;:clloooooool:;;cc;,,;co0MMWNXXWNXMMMMKkxxk:.        ";
  data[150] = "             ..;clloooooooooolc:lool:;:lxONMMNOdl:ldddddl ..         ";
  data[151] = "             ..:ooooooooooooooooooooooooodONMMMWx:::. ...            ";
  data[152] = "             ..,ooooooooolloooooooooooooood0MMMMWNNXc.               ";
  data[153] = "              .. ;cooooool:cooooooooooooooodxxkKWWNXc.               ";
  data[154] = "              ..   dxkO0O0c:xdddddoooooooooooloxkklc .               ";
  data[155] = "             ..:  :XWKllko ;dkKKKK0OOkd:,;lxk0XNX:  .                ";
  data[156] = "             .;O: lMO   .. .. :::cllll:.  .::dOxc..                  ";
  data[157] = "             .. ..o0l. .     ............... ., ..                   ";
  data[158] = "               .. ,:: .                                              ";
  data[159] = "                                                                     ";
  data[160] = "                                                                     ";
  data[161] = "                                                                     ";
  data[162] = "                                        ...                          ";
  data[163] = "                                      ... ,...        ...   ..       ";
  data[164] = "                                      ....;;;.......... ,;cc .       ";
  data[165] = "                                      ...,o;  .....,,. ;;xNx .       ";
  data[166] = "                                   ..  ..;d:.;;,cllooc;.cKk:.        ";
  data[167] = "                   .......      ........,;;coooooxkkxoxd: ..         ";
  data[168] = "                ................  . ,;;,,loooooo; dKkokd..           ";
  data[169] = "              ..... ,,;;;;,...  ... ;;:llddxkkkkdox000K0ko:,.        ";
  data[170] = "              ... ,;;:cccc:..,;; .. ;;codOXNMMMMMMMMMMMMMMMl.        ";
  data[171] = "             ...;:::clooool,,:llc . ;;coOWMMMMMMMMMMMMk,,kMl.        ";
  data[172] = "             ..,:llloooooool;coool:;,,:l0MMWNXXWNXMMMMKxddd;.        ";
  data[173] = "             ..clooooooooooolloooooolcclxXMMMNOdl:ldddddc ..         ";
  data[174] = "             ..:oooooooooooooooooooooooookNMMMMWx:::. ...            ";
  data[175] = "             ...coooooooooooooooooooooooodOWMMMMWNNNc.               ";
  data[176] = "              ....,coooc;oxooooooooooooooooONNWMMMWNc.               ";
  data[177] = "               .. .oOkd, lK0000OOxddlllloolloodkO0Ok;.               ";
  data[178] = "               ..cxXW0:. .;:ldddxxdolc, :loddkOOx: ...               ";
  data[179] = "               ..  c0c.     ..............ck0KXN0, ..                ";
  data[180] = "               ....., .                 .. , :lc;..                  ";
  data[181] = "                                           ......                    ";
  data[182] = "                                                                     ";
  data[183] = "                                                                     ";
  data[184] = "                                                                     ";
  data[185] = "                                                                     ";
  data[186] = "                                               ...                   ";
  data[187] = "                                             ... ,...      .. ...    ";
  data[188] = "                                           .....;o, .    ... ;;..    ";
  data[189] = "                                          .... :,;  ...  . .;,oc.    ";
  data[190] = "                     ...............    .. .,.;d:;;.,clloc;;.cx .    ";
  data[191] = "                   .....  ,,,, ... .. ..... ;;;;coooooooooooc; .     ";
  data[192] = "                  ... ;cllll:... , ..  ..,,;::loooooocckkookk .      ";
  data[193] = "                  .. :clooooc  ;;;;,. .. ;;cooooooooo  :xoox; .      ";
  data[194] = "                ....;clloooolc;;:lc;. . ,;clodk0XXKK0xldkO0K0ko,.    ";
  data[195] = "                . .,cooooooooolllool;.. :loooOWMMMMMMMMMMMMKkkKl.    ";
  data[196] = "                ...;looooooooooooooooo::looooOWMWXXNWNXMMMMk, c:.    ";
  data[197] = "                  . oooooooooooooooooollooooodKMMXd:codONNNNKd .     ";
  data[198] = "              ..;::dOdooooooooooooooooooooooooxKWMKkxdllc,;;; .      ";
  data[199] = "              ..dKNMNOdoooocck0kxooolllooooooood0MMMMMMK;.           ";
  data[200] = "               .. :dkxl:;; .c0XNXK0x: :oooooooldKMMMMMWc. ...        ";
  data[201] = "                  ...........,:cod0Xo;:x00OkkkccKNNNKxc,cocc .       ";
  data[202] = "                              .... :::.:NMMWXk .,::: ...    ..       ";
  data[203] = "                                  ..... cxXNN0; .....  ......        ";
  data[204] = "                                        ..,:::,.                     ";
  data[205] = "                                                                     ";
  data[206] = "                                                                     ";
  data[207] = "                                                                     ";
  data[208] = "                                                                     ";
  data[209] = "                                                                     ";
  data[210] = "                                          ......            ....     ";
  data[211] = "                                         ... ;;..        .....,..    ";
  data[212] = "                         ..........      .....;;........... ,;c..    ";
  data[213] = "                      ............  ..... .. :k: ... ,;;, , :0d..    ";
  data[214] = "                    ... ,;::;;,.......  . . .;lccccllooooc; co,.     ";
  data[215] = "                   ...;cllool:...,, . ..  .,;coooooooxkxoxkk;.       ";
  data[216] = "                   ..,cooooooc:cc:;.... ;;:ccloooooo::O0o0WO .       ";
  data[217] = "                   ..:loooooollool:... ,;cloodxkkxdo;.cxx0Kd; .      ";
  data[218] = "               .. ,..cooooooooooool .,,;looxOKWMMWXXXXXXWMMMMK:.     ";
  data[219] = "              . dk0d:clooooooccooooc;;;cooo0MMMWWMMMMMMMMk,,,kl.     ";
  data[220] = "              ..::kMNOdoooooo;;ooooooolloookXNMWKKWMKKMMMOlc:c,.     ";
  data[221] = "              ....,:oxkkdddl:,cooooooooooooddOWMNkllc:ldddddc .      ";
  data[222] = "                    ..,; ;;,:kXK0dloooooooooodKMMWXKOc.......        ";
  data[223] = "                       .....:OWMOlooooooollddkXMMMWNNc.              ";
  data[224] = "                            . ;;l0K000Okl:dO0KNNNNkoc .              ";
  data[225] = "                              . :NMMWXkc,cxxxO0d:::: .               ";
  data[226] = "                              . ;KWMx . .    ,;.. lkx,.              ";
  data[227] = "                              ...,::,..         ..  ,..              ";
  data[228] = "                                                                     ";
  data[229] = "                                                                     ";
  data[230] = "                                                                     ";
  data[231] = "                                                                     ";
  data[232] = "                                                                     ";
  data[233] = "                                       ... ....        ........      ";
  data[234] = "                                       ..;l: ,..      ......,,..     ";
  data[235] = "                          ...          .. ,cc: .....  ..,,,;c,..     ";
  data[236] = "                     .............. ... ..;dd:;;,cllloc;.;kxl .      ";
  data[237] = "                   .... ,,,;;,... .......,;;;cooooooooooc;; .        ";
  data[238] = "                  .. ;clllc;.. , ..... ,,,loooooocclkkokk  .         ";
  data[239] = "                ....:loooooc  ;;; ... ,;:looooooo   :xox:  .         ";
  data[240] = "                . .;looooool;;clc;.. ;;:ldk0KKX0OdlldOKX0kko,.       ";
  data[241] = "                . .coooooooolloool; ,;;loOWMMMMMMMMMMMMKkkkKl.       ";
  data[242] = "                . .:looooooolloooool:;cooOWMMWXXWXNMMMMk,  c:.       ";
  data[243] = "                . .;cooooooolclooooolclooxXMMMXdcoddONNNKd: .        ";
  data[244] = "                ... ;clooooool:,:looooooodONMMMKll:. ,;;; ..         ";
  data[245] = "                  .. dkxddddol;..,:looooooxXMMMMWNxc .               ";
  data[246] = "                  ..dNWNNNKd;;,  ;:loooodkKWMMMMMWl .                ";
  data[247] = "                  ..dXNKko,,l0KOkdoooooodOXNNNNKxl ..                ";
  data[248] = "                   . ::. ..:NMMMNk:,,     ,:::: ..                   ";
  data[249] = "                    ....... :::::;..... .;:lo  .                     ";
  data[250] = "                                       ..  ,;..                      ";
  data[251] = "                                                                     ";
  data[252] = "                                                                     ";
  data[253] = "                                                                     ";
  data[254] = "                                                                     ";
  data[255] = "                                                                     ";
  data[256] = "                                    ...    ...       ........        ";
  data[257] = "                                    . .,  ::,............  . .       ";
  data[258] = "                                    . ...co;. .. ,;;;,. ;ccl .       ";
  data[259] = "                      .........    .. .  ;lc;cc:loooooc :ddl .       ";
  data[260] = "                   ............  ....  .,coooooooxkkxoxk; ..         ";
  data[261] = "                .... ;:::;;; .......,;;;cloooooo; dKkokd..           ";
  data[262] = "                . .,:loool:;..  ... ;;:lodk000kd: cxk00xl,..         ";
  data[263] = "               ... :loooool; ,;;,.. :lloxKWMMMWXXXXNWMMMMKk:.        ";
  data[264] = "               ..;:looooooolclllc..,cooo0MMWNWMMMMMMMMk,,kMl.        ";
  data[265] = "               ..;cooooooooooooooc:cloookNMWNXOxkOKNNN0o:;:,.        ";
  data[266] = "               ..;cooooooooolloooooooooodONMMMk,,  ::::: .           ";
  data[267] = "               ...,loooooooollcclooooooooxXMMMWXklcc. ...            ";
  data[268] = "                ... :lodddddoo;.;doloooolkWMMMMMMW0d;.               ";
  data[269] = "                  ...;xKNNNX0o..cl,;clloll0MMMMMMWl .                ";
  data[270] = "                    .,kNMMMKd;....;dkkxdd:dNNNNKxl ..                ";
  data[271] = "                    ..c0NWMl lc:.,0WMMN0l. :::: ..                   ";
  data[272] = "                     ..,;:;..;co,,dkkkko,.......                     ";
  data[273] = "                          .........    ...                           ";
  data[274] = "                                                                     ";
  data[275] = "                                                                     ";
  data[276] = "                                                                     ";
  data[277] = "                                                                     ";
  data[278] = "                                      ......          .......        ";
  data[279] = "                                      ..,, . .......... ; ....       ";
  data[280] = "                                      ....:;  .....,,. ; ;::..       ";
  data[281] = "                                    .. ..;d:.;;,cllooc;.;xdl .       ";
  data[282] = "                                  ......,;;coooooooooooc; ..         ";
  data[283] = "                    ........ .......,;;,,loooooocckKkokk .           ";
  data[284] = "                  ........... ..  .,;;;cldxkkkxd;.ckxx0d; ..         ";
  data[285] = "                .....,;;;;;,... .. ;;;codONMMMNK0000KNMMM0l,.        ";
  data[286] = "              ..... ;::clllc, ,;,..;:lloOWMMMMMMMMMMMMKkkKMl.        ";
  data[287] = "              .. ,;clllooooolc;;cc;,:ooo0MMWNXXWNNMMMMk, ck:.        ";
  data[288] = "              ..,;cooooooooooollloolclloxKWMMNOdl:lddddoc ..         ";
  data[289] = "              ..;;coooooooooooooooooooooodONMMMWkc::,. ..            ";
  data[290] = "              ..,;coooooolllloooooooooooood0MMMMMWNNXc.              ";
  data[291] = "               ..;;cloooooolccloooooooooooox0XMMMMWN0;.              ";
  data[292] = "              .... ,;clloddkOcc00Oxddoc:loolloxXMWKk;.               ";
  data[293] = "              .. .....ckOKN0k;,dOXXXK0ko:lO000:ckl; ..               ";
  data[294] = "              ..loo   ,O0NMO  .. ::cllll :NMMMl....                  ";
  data[295] = "              . dkO: ..;coxk;.  .....    .cxkk:..                    ";
  data[296] = "              ..  ,..  .......           ......                      ";
  data[297] = "                                                                     ";
  data[298] = "                                                                     ";
  data[299] = "                                                                     ";
  data[300] = "                                       ...                           ";
  data[301] = "                                    ... ;, ...       ...   ..        ";
  data[302] = "                                    . .  ::;;,........ :::c..        ";
  data[303] = "                                    . . .od; ;.....  .;:;xNc.        ";
  data[304] = "                                    . . .;d:.;:;cllooc;.cKk:.        ";
  data[305] = "                                  ...  .,;;coooooxkkxoxdc ..         ";
  data[306] = "                  .................. ,,;;loooooo; dKkokd..           ";
  data[307] = "               .....  ,,,, ..... .. ;;;cldxkkkkkdox000K0ko:,.        ";
  data[308] = "              .....,;;;;;;;.... ... ;;codONMMMMMMMMMMMMMMMMl.        ";
  data[309] = "             ... ,;;;clllll:, ,;,.. ;;coOWMMMMMMMMMMMMk,,kMl.        ";
  data[310] = "             ..,;:clloooooool:;;cc;,,;co0MMWNXXWNXMMMMKkxxk:.        ";
  data[311] = "             ..;clloooooooooolc:lool:;:lxONMMNOdl:ldddddl ..         ";
  data[312] = "             ..:ooooooooooooooooooooooooodONMMMWx:::. ...            ";
  data[313] = "             ..,ooooooooolloooooooooooooood0MMMMWNNXc.               ";
  data[314] = "              .. ;cooooool:cooooooooooooooodxxkKWWNXc.               ";
  data[315] = "              ..   dxkO000c:xdddddoooooooooooloxkklc .               ";
  data[316] = "             ..:  :XWMMKko ;dkKKKK0OOkd:,;lxk0XNX:  .                ";
  data[317] = "             .;O: lMMM0,.. .. :::cllll:.  .::dOxc..                  ";
  data[318] = "             .. ..oWMk .     ............... ., ..                   ";
  data[319] = "               .. ,:: .                                              ";
  data[320] = "                                                                     ";
  data[321] = "                                                                     ";
  data[322] = "                                                                     ";
  data[323] = "                                        ...                          ";
  data[324] = "                                      ... ,...        ...   ..       ";
  data[325] = "                                      ....;;;.......... ,;cc .       ";
  data[326] = "                                      ...,o;  .....,,. ;;xNx .       ";
  data[327] = "                                   ..  ..;d:.;;,cllooc;.cKk:.        ";
  data[328] = "                   .......      ........,;;coooooxkkxoxd: ..         ";
  data[329] = "                ................  . ,;;,,loooooo; dKkokd..           ";
  data[330] = "              ..... ,,;;;;,...  ... ;;:llddxkkkkdox000K0ko:,.        ";
  data[331] = "              ... ,;;:cccc:..,;; .. ;;codOXNMMMMMMMMMMMMMMMl.        ";
  data[332] = "             ...;:::clooool,,:llc . ;;coOWMMMMMMMMMMMMk,,kMl.        ";
  data[333] = "             ..,:llloooooool;coool:;,,:l0MMWNXXWNXMMMMKxddd;.        ";
  data[334] = "             ..clooooooooooolloooooolcclxXMMMNOdl:ldddddc ..         ";
  data[335] = "             ..:oooooooooooooooooooooooookNMMMMWx:::. ...            ";
  data[336] = "             ...coooooooooooooooooooooooodOWMMMMWNNNc.               ";
  data[337] = "              ....,coooc;oxooooooooooooooooONNWMMMWNc.               ";
  data[338] = "               .. .oOkd, lK0000OOxddlllloolloodkO0Ok;.               ";
  data[339] = "               ..cxXW0:. .;:ldddxxdolc, :loddkOOx: ...               ";
  data[340] = "               ..  c0c.     ..............ck0KXN0, ..                ";
  data[341] = "               ....., .                 .. , :lc;..                  ";
  data[342] = "                                           ......                    ";
  data[343] = "                                                                     ";
  data[344] = "                                                                     ";
  data[345] = "                                                                     ";
  data[346] = "                                                                     ";
  data[347] = "                                             .....          ....     ";
  data[348] = "                                           .... ;,...    .... ...    ";
  data[349] = "                                          ...... :   ....... ;d:.    ";
  data[350] = "                                        .. .,.;k:   . ,;;,  .cO;.    ";
  data[351] = "                     ..........       ......;,;lccc;:loooooc c:.     ";
  data[352] = "                    ............. ... .. ,,,;;coooooooxkxooxk;.      ";
  data[353] = "                  .... ,,,;;;;. ..... .. ;;;:cloooooo; dkookd..      ";
  data[354] = "                  ...,::;:cc:;....,,. .. ;:loodk0000kc :dk00xl,.     ";
  data[355] = "                ....;:cllloolc;, ,;:; .. ;looxKWMMMMWXXXXWMMMMK:.    ";
  data[356] = "                . .,:lloooooooll:;loooc;,cooo0MMWWMMMMMMMMMk,,kl.    ";
  data[357] = "                ...,looooooooooolloooooolllooOWMWXOdxkOKNNN0o:;,.    ";
  data[358] = "                  .,oooooooooooooooooooooooooxXMMM0lc:  ::::: .      ";
  data[359] = "                  .,ooooooooooooooooooooooooodkXMMMMW0dc......       ";
  data[360] = "                  .,oooooooldxoooooooooooooooooOWMMMMMMWc ..         ";
  data[361] = "               ... oOxdoooc.:O0000Okdddooooooolcd0NNWMW0:  .         ";
  data[362] = "              .,dkKMWOl;  ... ::ldxxkKKKk::looddxxlclOk ....         ";
  data[363] = "              ..l0XMO,..        .... ::cl  :xxOKNMOllc ...           ";
  data[364] = "               .. ;: .              ....... ;;:lkXWMK:.              ";
  data[365] = "                                              ...,::,.               ";
  data[366] = "                                                                     ";
  data[367] = "                                                                     ";
}
