#include "LinearAlgebra.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(LinearAlgebraTests, DotProductBlas) {
  std::vector<double> a = {1.0, 2.0, 3.0};
  std::vector<double> b = {4.0, 5.0, 6.0};
  EXPECT_DOUBLE_EQ(32.0, LinearAlgebra::dotBlas(a, b));
}

TEST(LinearAlgebraTests, MatrixMultiplicationBlas) {
  std::vector<std::vector<double>> matrix_a = {{1.0, 2.0}, {3.0, 4.0}};
  std::vector<std::vector<double>> matrix_b = {{2.0, 0.0}, {1.0, 3.0}};
  auto result = LinearAlgebra::matmulBlas(matrix_a, matrix_b);
  EXPECT_DOUBLE_EQ(result[0][0], 4.0);
  EXPECT_DOUBLE_EQ(result[0][1], 6.0);
  EXPECT_DOUBLE_EQ(result[1][0], 10.0);
  EXPECT_DOUBLE_EQ(result[1][1], 12.0);
}


TEST(LinearAlgebraTests, cosineSimilarity) {
  std::vector<std::vector<double>> matrix_a = { { 3, 2, 0, 5 }, { 1, 0, 0, 0 }};
  std::vector<std::vector<double>> matrix_b = { { 3, 2, 0, 5 }, { 1, 0, 0, 0 } };
  auto result = LinearAlgebra::cosineSimilarity(matrix_a, matrix_b);
  
  EXPECT_DOUBLE_EQ(result[0][0], 1.0);
  EXPECT_DOUBLE_EQ(std::ceil(result[0][1] * 100.0)/100, 0.49);
  EXPECT_DOUBLE_EQ(std::ceil(result[1][0] * 100.0)/100, 0.49);
  EXPECT_DOUBLE_EQ(result[1][1], 1.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
