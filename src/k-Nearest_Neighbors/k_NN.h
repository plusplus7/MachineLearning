#ifndef MACHINELEARNING_K_NEAREST_NEIGHBORS_K_NN_
#define MACHINELEARNING_K_NEAREST_NEIGHBORS_K_NN_

class k_NN {
 public:
  bool train(char *filename, int dataset_num, int feature_num, int label_num);
  int classify(double *x, int k);
  void clear(); 
 protected: 
 private:
  double **trainset_input;
  int *trainset_output;
  double *max_values, *min_values;
  int n;
  int m;
 
  void readfile(char *filename);
  double get_dist(double *a,double *b);
};

#endif //end of MACHINELEARNING_K_NEAREST_NEIGHBORS_K_NN_

