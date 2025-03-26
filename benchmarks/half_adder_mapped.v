// Benchmark "half_adder" written by ABC on Sun May 14 14:06:25 2023

module half_adder (
    a, b,
    cout, sum  );
  input  a, b;
  output cout, sum;
  wire new_n5_, new_n6_, new_n8_;
  inv1 g0(.a(a), .O(new_n5_));
  inv1 g1(.a(b), .O(new_n6_));
  nor2 g2(.a(new_n6_), .b(new_n5_), .O(cout));
  nor2 g3(.a(b), .b(a), .O(new_n8_));
  nor2 g4(.a(new_n8_), .b(cout), .O(sum));
endmodule
