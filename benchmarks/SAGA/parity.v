// Benchmark "top" written by ABC on Tue Nov 26 20:40:41 2024

module top ( 
    pp, pa, pb, pc, pd, pe, pf, pg, ph, pi, pj, pk, pl, pm, pn, po,
    pq  );
  input  pp, pa, pb, pc, pd, pe, pf, pg, ph, pi, pj, pk, pl, pm, pn, po;
  output pq;
  wire new_n18, new_n19, new_n20, new_n21, new_n22, new_n23, new_n24,
    new_n25, new_n26, new_n27, new_n28, new_n29, new_n30, new_n31, new_n32,
    new_n33, new_n34, new_n35, new_n36, new_n37, new_n38, new_n39, new_n40,
    new_n41, new_n42, new_n43, new_n44, new_n45, new_n46, new_n47, new_n48,
    new_n49, new_n50, new_n51, new_n52, new_n53, new_n54, new_n55, new_n56,
    new_n57, new_n58, new_n59, new_n60, new_n61, new_n62, new_n63, new_n64,
    new_n65, new_n66, new_n67, new_n68, new_n69, new_n70, new_n71, new_n72,
    new_n73, new_n74, new_n75, new_n76, new_n77, new_n78, new_n79, new_n80,
    new_n81, new_n82, new_n83, new_n84, new_n85, new_n86, new_n87, new_n88,
    new_n89, new_n90, new_n91, new_n92;
  nor2 g00(.a(pc), .b(pb), .O(new_n18));
  inv1 g01(.a(pb), .O(new_n19));
  inv1 g02(.a(pc), .O(new_n20));
  nor2 g03(.a(new_n20), .b(new_n19), .O(new_n21));
  nor2 g04(.a(new_n21), .b(new_n18), .O(new_n22));
  inv1 g05(.a(new_n22), .O(new_n23));
  inv1 g06(.a(pa), .O(new_n24));
  nor2 g07(.a(pd), .b(new_n24), .O(new_n25));
  inv1 g08(.a(pd), .O(new_n26));
  nor2 g09(.a(new_n26), .b(pa), .O(new_n27));
  nor2 g10(.a(new_n27), .b(new_n25), .O(new_n28));
  inv1 g11(.a(new_n28), .O(new_n29));
  nor2 g12(.a(new_n29), .b(new_n23), .O(new_n30));
  nor2 g13(.a(new_n28), .b(new_n22), .O(new_n31));
  nor2 g14(.a(new_n31), .b(new_n30), .O(new_n32));
  inv1 g15(.a(new_n32), .O(new_n33));
  inv1 g16(.a(pe), .O(new_n34));
  nor2 g17(.a(pf), .b(new_n34), .O(new_n35));
  inv1 g18(.a(pf), .O(new_n36));
  nor2 g19(.a(new_n36), .b(pe), .O(new_n37));
  nor2 g20(.a(new_n37), .b(new_n35), .O(new_n38));
  inv1 g21(.a(new_n38), .O(new_n39));
  inv1 g22(.a(pg), .O(new_n40));
  nor2 g23(.a(ph), .b(new_n40), .O(new_n41));
  inv1 g24(.a(ph), .O(new_n42));
  nor2 g25(.a(new_n42), .b(pg), .O(new_n43));
  nor2 g26(.a(new_n43), .b(new_n41), .O(new_n44));
  nor2 g27(.a(new_n44), .b(new_n39), .O(new_n45));
  inv1 g28(.a(new_n44), .O(new_n46));
  nor2 g29(.a(new_n46), .b(new_n38), .O(new_n47));
  nor2 g30(.a(new_n47), .b(new_n45), .O(new_n48));
  inv1 g31(.a(new_n48), .O(new_n49));
  nor2 g32(.a(new_n49), .b(new_n33), .O(new_n50));
  nor2 g33(.a(new_n48), .b(new_n32), .O(new_n51));
  nor2 g34(.a(new_n51), .b(new_n50), .O(new_n52));
  inv1 g35(.a(new_n52), .O(new_n53));
  nor2 g36(.a(pk), .b(pj), .O(new_n54));
  inv1 g37(.a(pj), .O(new_n55));
  inv1 g38(.a(pk), .O(new_n56));
  nor2 g39(.a(new_n56), .b(new_n55), .O(new_n57));
  nor2 g40(.a(new_n57), .b(new_n54), .O(new_n58));
  inv1 g41(.a(new_n58), .O(new_n59));
  inv1 g42(.a(pi), .O(new_n60));
  nor2 g43(.a(pl), .b(new_n60), .O(new_n61));
  inv1 g44(.a(pl), .O(new_n62));
  nor2 g45(.a(new_n62), .b(pi), .O(new_n63));
  nor2 g46(.a(new_n63), .b(new_n61), .O(new_n64));
  inv1 g47(.a(new_n64), .O(new_n65));
  nor2 g48(.a(new_n65), .b(new_n59), .O(new_n66));
  nor2 g49(.a(new_n64), .b(new_n58), .O(new_n67));
  nor2 g50(.a(new_n67), .b(new_n66), .O(new_n68));
  inv1 g51(.a(new_n68), .O(new_n69));
  inv1 g52(.a(pm), .O(new_n70));
  nor2 g53(.a(pn), .b(new_n70), .O(new_n71));
  inv1 g54(.a(pn), .O(new_n72));
  nor2 g55(.a(new_n72), .b(pm), .O(new_n73));
  nor2 g56(.a(new_n73), .b(new_n71), .O(new_n74));
  inv1 g57(.a(new_n74), .O(new_n75));
  inv1 g58(.a(pp), .O(new_n76));
  nor2 g59(.a(po), .b(new_n76), .O(new_n77));
  inv1 g60(.a(po), .O(new_n78));
  nor2 g61(.a(new_n78), .b(pp), .O(new_n79));
  nor2 g62(.a(new_n79), .b(new_n77), .O(new_n80));
  nor2 g63(.a(new_n80), .b(new_n75), .O(new_n81));
  inv1 g64(.a(new_n80), .O(new_n82));
  nor2 g65(.a(new_n82), .b(new_n74), .O(new_n83));
  nor2 g66(.a(new_n83), .b(new_n81), .O(new_n84));
  nor2 g67(.a(new_n84), .b(new_n69), .O(new_n85));
  inv1 g68(.a(new_n84), .O(new_n86));
  nor2 g69(.a(new_n86), .b(new_n68), .O(new_n87));
  nor2 g70(.a(new_n87), .b(new_n85), .O(new_n88));
  inv1 g71(.a(new_n88), .O(new_n89));
  nor2 g72(.a(new_n89), .b(new_n53), .O(new_n90));
  nor2 g73(.a(new_n88), .b(new_n52), .O(new_n91));
  nor2 g74(.a(new_n91), .b(new_n90), .O(new_n92));
  inv1 g75(.a(new_n92), .O(pq));
endmodule


