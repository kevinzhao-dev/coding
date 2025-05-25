
#include <vector>
using namespace std;

// TODO: replace with a proper implementation. For now this stub simply
// iterates over the array and returns true so the file builds successfully.
bool SmallerPrefix(const vector<int> &arr) {
  int sp = 0, fp = 0;
  while (fp < static_cast<int>(arr.size())) {
    (void)sp;  // suppress unused variable warning
    fp++;
  }
  return true;
}