// Benchmark "top" written by ABC on Tue Nov 26 20:40:41 2024

module top ( 
    pa, pb, pc, pd, pe, pf, pg, ph, pi, pj,
    pp, pq, pk, pl, pm, pn, po  );
  input  pa, pb, pc, pd, pe, pf, pg, ph, pi, pj;
  output pp, pq, pk, pl, pm, pn, po;
  wire new_n18, new_n19, new_n20, new_n21, new_n22, new_n23, new_n24,
    new_n25, new_n26, new_n27, new_n28, new_n29, new_n30, new_n31, new_n32,
    new_n33, new_n34, new_n35, new_n36, new_n37, new_n38, new_n39, new_n40,
    new_n41, new_n42, new_n43, new_n44, new_n45, new_n46, new_n47, new_n48,
    new_n49, new_n50, new_n51, new_n53, new_n54, new_n55, new_n56, new_n57,
    new_n58, new_n59, new_n61, new_n62, new_n63, new_n64, new_n65, new_n66,
    new_n67, new_n68, new_n69, new_n70, new_n71, new_n74, new_n76, new_n77,
    new_n78, new_n80, new_n81;
  inv1 g00(.a(ph), .O(new_n18));
  inv1 g01(.a(pi), .O(new_n19));
  inv1 g02(.a(pj), .O(new_n20));
  nor2 g03(.a(new_n20), .b(new_n19), .O(new_n21));
  nor2 g04(.a(new_n21), .b(new_n18), .O(new_n22));
  nor2 g05(.a(pb), .b(pa), .O(new_n23));
  inv1 g06(.a(new_n23), .O(new_n24));
  inv1 g07(.a(pc), .O(new_n25));
  nor2 g08(.a(new_n19), .b(ph), .O(new_n26));
  nor2 g09(.a(new_n26), .b(new_n25), .O(new_n27));
  inv1 g10(.a(new_n27), .O(new_n28));
  nor2 g11(.a(new_n28), .b(new_n24), .O(new_n29));
  inv1 g12(.a(new_n29), .O(new_n30));
  nor2 g13(.a(new_n30), .b(new_n22), .O(new_n31));
  inv1 g14(.a(pg), .O(new_n32));
  inv1 g15(.a(new_n26), .O(new_n33));
  inv1 g16(.a(pf), .O(new_n34));
  nor2 g17(.a(new_n20), .b(new_n34), .O(new_n35));
  inv1 g18(.a(new_n35), .O(new_n36));
  nor2 g19(.a(new_n36), .b(new_n33), .O(new_n37));
  nor2 g20(.a(new_n37), .b(new_n32), .O(new_n38));
  inv1 g21(.a(new_n38), .O(new_n39));
  nor2 g22(.a(pj), .b(new_n18), .O(new_n40));
  inv1 g23(.a(new_n40), .O(new_n41));
  inv1 g24(.a(pd), .O(new_n42));
  nor2 g25(.a(pe), .b(new_n42), .O(new_n43));
  inv1 g26(.a(new_n43), .O(new_n44));
  nor2 g27(.a(new_n44), .b(new_n41), .O(new_n45));
  nor2 g28(.a(pj), .b(pi), .O(new_n46));
  nor2 g29(.a(new_n46), .b(new_n45), .O(new_n47));
  inv1 g30(.a(new_n47), .O(new_n48));
  nor2 g31(.a(new_n48), .b(new_n39), .O(new_n49));
  inv1 g32(.a(new_n49), .O(new_n50));
  nor2 g33(.a(new_n50), .b(new_n31), .O(new_n51));
  inv1 g34(.a(new_n51), .O(pp));
  nor2 g35(.a(new_n20), .b(new_n18), .O(new_n53));
  nor2 g36(.a(pj), .b(ph), .O(new_n54));
  nor2 g37(.a(new_n54), .b(new_n53), .O(new_n55));
  nor2 g38(.a(new_n55), .b(pi), .O(new_n56));
  nor2 g39(.a(new_n56), .b(new_n39), .O(new_n57));
  inv1 g40(.a(new_n57), .O(new_n58));
  nor2 g41(.a(new_n41), .b(new_n19), .O(new_n59));
  inv1 g42(.a(new_n59), .O(pk));
  inv1 g43(.a(pe), .O(new_n61));
  nor2 g44(.a(new_n61), .b(new_n42), .O(new_n62));
  inv1 g45(.a(new_n62), .O(new_n63));
  nor2 g46(.a(new_n63), .b(pk), .O(new_n64));
  inv1 g47(.a(new_n53), .O(new_n65));
  nor2 g48(.a(new_n24), .b(pc), .O(new_n66));
  inv1 g49(.a(new_n66), .O(new_n67));
  nor2 g50(.a(new_n67), .b(new_n65), .O(new_n68));
  nor2 g51(.a(new_n68), .b(new_n64), .O(new_n69));
  inv1 g52(.a(new_n69), .O(new_n70));
  nor2 g53(.a(new_n70), .b(new_n58), .O(new_n71));
  inv1 g54(.a(new_n71), .O(pq));
  inv1 g55(.a(new_n56), .O(pl));
  inv1 g56(.a(new_n46), .O(new_n74));
  nor2 g57(.a(new_n74), .b(ph), .O(pm));
  nor2 g58(.a(new_n33), .b(pj), .O(new_n76));
  inv1 g59(.a(new_n76), .O(new_n77));
  nor2 g60(.a(new_n77), .b(new_n67), .O(new_n78));
  inv1 g61(.a(new_n78), .O(pn));
  inv1 g62(.a(new_n22), .O(new_n80));
  nor2 g63(.a(new_n80), .b(new_n32), .O(new_n81));
  inv1 g64(.a(new_n81), .O(po));
endmodule


