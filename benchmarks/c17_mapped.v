// Benchmark "../also-gitee/benchmarks/c17" written by ABC on Fri Jul 28 15:01:52 2023
module \../also-gitee/benchmarks/c17  (
    pi0, pi1, pi2, pi3, pi4,
    po0, po1  );
  input  pi0, pi1,
      pi2, pi3, pi4;
  output po0,
      po1;
  wire new_n8_, new_n9_, new_n10_,
      new_n11_, new_n12_, new_n13_, new_n14_,
      new_n15_, new_n17_,
      new_n18_, new_n19_;
  inv1 g00(.a(pi2), .O(new_n8_));
  inv1 g01(.a(pi1), .O(new_n9_));
  inv1 g02(.a(pi3), .O(new_n10_));
  nor2 g03(.a(new_n10_), .b(new_n9_), .O(new_n11_));
  nor2 g04(.a(new_n11_), .b(new_n8_), .O(new_n12_));
  inv1 g05(.a(pi0), .O(new_n13_));
  nor2 g06(.a(new_n9_), .b(new_n13_), .O(new_n14_));
  nor2 g07(.a(new_n14_), .b(new_n12_), .O(new_n15_));
  inv1 g08(.a(new_n15_), .O(po0));
  inv1 g09(.a(pi4), .O(new_n17_));
  nor2 g10(.a(new_n11_), .b(new_n17_), .O(new_n18_));
  nor2 g11(.a(new_n18_), .b(new_n12_), .O(new_n19_));
  inv1 g12(.a(new_n19_), .O(po1));
  endmodule
