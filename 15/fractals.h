// all functions assume starting with penDown()
//
namespace fract {

void kochCurve(double len, int level); // when finished moves len forward
void kochCurveAlt(double len, int sign, int level); // when finished moves len forward
void sTriangle(double side, int level); // returns to starting position
void binaryTree(double boxHeight, double boxWidth, int level); // returns to starting position
void canopy(double step, int level, double angle = 60, double ratio = 2./3); // returns to starting position
void hilbertCurve(double step, int sign, int level); // when finished moves step*(2^{level+1}-1) forward

}
