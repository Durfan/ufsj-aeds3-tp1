#define NisValide(ncoords) (( ncoords >= 1 && ncoords <= 100 ) ? 1 : 0)
#define PisValide(dot) (( dot > 0 && dot <= 10000 ) ? 1 : 0)

void chkFILE(char *file);
void showerro(int erro, int line);
void ask();