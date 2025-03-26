// Benchmark "full_adder_1bit" written by ABC on Mon May  6 10:37:42 2024

module full_adder_1bit ( 
    A, B, Cin,
    S, Cout  );
  input  A, B, Cin;
  output S, Cout;
  wire new_n6, new_n7, new_n8, new_n9, new_n10, new_n11, new_n12, new_n13,
    new_n14, new_n16;
  inv1 g00(.a(Cin), .O(new_n6));
  inv1 g01(.a(A), .O(new_n7));
  inv1 g02(.a(B), .O(new_n8));
  nor2 g03(.a(new_n8), .b(new_n7), .O(new_n9));
  nor2 g04(.a(B), .b(A), .O(new_n10));
  nor2 g05(.a(new_n10), .b(new_n9), .O(new_n11));
  inv1 g06(.a(new_n11), .O(new_n12));
  nor2 g07(.a(new_n12), .b(new_n6), .O(new_n13));
  nor2 g08(.a(new_n11), .b(Cin), .O(new_n14));
  nor2 g09(.a(new_n14), .b(new_n13), .O(S));
  nor2 g10(.a(new_n13), .b(new_n9), .O(new_n16));
  inv1 g11(.a(new_n16), .O(Cout));
endmodule


