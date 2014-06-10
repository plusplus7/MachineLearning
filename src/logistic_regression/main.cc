#include "logistic_regression.h"
int main() {
	LogisticRegression *lr=new LogisticRegression();
	lr->work("../../data/logistic_regression_data.data");
	lr->show_result();
	delete lr;
	return 0;
}
