// Benchmark "top" written by ABC on Tue Nov 26 20:40:42 2024

module top ( 
    rmwb, yskip, page, xskip, dmpst0, dmpst1, dmpst2, dmpst3,
    adctlp0b, adctlp1b, adctlp2b, dmnst0b, dmnst1b, dmnst2b, dmnst3b  );
  input  rmwb, yskip, page, xskip, dmpst0, dmpst1, dmpst2, dmpst3;
  output adctlp0b, adctlp1b, adctlp2b, dmnst0b, dmnst1b, dmnst2b, dmnst3b;
  wire new_n16, new_n17, new_n18, new_n19, new_n20, new_n21, new_n22,
    new_n23, new_n24, new_n25, new_n26, new_n27, new_n28, new_n29, new_n30,
    new_n31, new_n32, new_n33, new_n34, new_n35, new_n36, new_n37, new_n38,
    new_n39, new_n40, new_n41, new_n42, new_n43, new_n44, new_n45, new_n46,
    new_n47, new_n48, new_n49, new_n51, new_n52, new_n53, new_n54, new_n55,
    new_n56, new_n57, new_n58, new_n59, new_n60, new_n61, new_n62, new_n63,
    new_n64, new_n65, new_n66, new_n67, new_n69, new_n70, new_n71, new_n73,
    new_n74, new_n75, new_n76, new_n77, new_n79, new_n80, new_n81, new_n82,
    new_n83, new_n84, new_n85, new_n86, new_n87, new_n88, new_n90, new_n91,
    new_n92, new_n94, new_n95, new_n96;
  inv1 g00(.a(dmpst1), .O(new_n16));
  nor2 g01(.a(dmpst2), .b(new_n16), .O(new_n17));
  inv1 g02(.a(new_n17), .O(new_n18));
  nor2 g03(.a(new_n18), .b(dmpst3), .O(new_n19));
  inv1 g04(.a(new_n19), .O(new_n20));
  nor2 g05(.a(dmpst0), .b(yskip), .O(new_n21));
  inv1 g06(.a(new_n21), .O(new_n22));
  nor2 g07(.a(new_n22), .b(new_n20), .O(new_n23));
  inv1 g08(.a(dmpst3), .O(new_n24));
  nor2 g09(.a(new_n24), .b(dmpst0), .O(new_n25));
  inv1 g10(.a(new_n25), .O(new_n26));
  nor2 g11(.a(new_n26), .b(new_n18), .O(new_n27));
  nor2 g12(.a(new_n27), .b(new_n23), .O(new_n28));
  inv1 g13(.a(new_n28), .O(new_n29));
  inv1 g14(.a(dmpst0), .O(new_n30));
  inv1 g15(.a(dmpst2), .O(new_n31));
  nor2 g16(.a(dmpst3), .b(new_n31), .O(new_n32));
  inv1 g17(.a(new_n32), .O(new_n33));
  nor2 g18(.a(new_n33), .b(new_n30), .O(new_n34));
  nor2 g19(.a(dmpst1), .b(new_n30), .O(new_n35));
  inv1 g20(.a(new_n35), .O(new_n36));
  nor2 g21(.a(new_n24), .b(dmpst2), .O(new_n37));
  inv1 g22(.a(new_n37), .O(new_n38));
  nor2 g23(.a(new_n38), .b(new_n36), .O(new_n39));
  nor2 g24(.a(new_n39), .b(new_n34), .O(new_n40));
  inv1 g25(.a(new_n40), .O(new_n41));
  nor2 g26(.a(new_n31), .b(dmpst1), .O(new_n42));
  inv1 g27(.a(new_n42), .O(new_n43));
  nor2 g28(.a(new_n43), .b(dmpst3), .O(new_n44));
  inv1 g29(.a(new_n44), .O(new_n45));
  nor2 g30(.a(new_n45), .b(xskip), .O(new_n46));
  nor2 g31(.a(new_n46), .b(new_n41), .O(new_n47));
  inv1 g32(.a(new_n47), .O(new_n48));
  nor2 g33(.a(new_n48), .b(new_n29), .O(new_n49));
  inv1 g34(.a(new_n49), .O(adctlp0b));
  nor2 g35(.a(new_n16), .b(new_n30), .O(new_n51));
  nor2 g36(.a(new_n51), .b(new_n42), .O(new_n52));
  nor2 g37(.a(new_n52), .b(dmpst3), .O(new_n53));
  nor2 g38(.a(new_n39), .b(new_n27), .O(new_n54));
  inv1 g39(.a(new_n54), .O(new_n55));
  nor2 g40(.a(new_n55), .b(new_n53), .O(new_n56));
  inv1 g41(.a(new_n56), .O(new_n57));
  inv1 g42(.a(page), .O(new_n58));
  nor2 g43(.a(dmpst1), .b(dmpst0), .O(new_n59));
  inv1 g44(.a(new_n59), .O(new_n60));
  nor2 g45(.a(new_n60), .b(dmpst3), .O(new_n61));
  inv1 g46(.a(new_n61), .O(new_n62));
  nor2 g47(.a(new_n62), .b(new_n58), .O(new_n63));
  nor2 g48(.a(new_n21), .b(new_n20), .O(new_n64));
  nor2 g49(.a(new_n64), .b(new_n63), .O(new_n65));
  inv1 g50(.a(new_n65), .O(new_n66));
  nor2 g51(.a(new_n66), .b(new_n57), .O(new_n67));
  inv1 g52(.a(new_n67), .O(adctlp1b));
  nor2 g53(.a(new_n61), .b(new_n19), .O(new_n69));
  inv1 g54(.a(new_n69), .O(new_n70));
  nor2 g55(.a(new_n70), .b(new_n57), .O(new_n71));
  inv1 g56(.a(new_n71), .O(adctlp2b));
  inv1 g57(.a(rmwb), .O(new_n73));
  nor2 g58(.a(dmpst0), .b(xskip), .O(new_n74));
  nor2 g59(.a(new_n74), .b(new_n73), .O(new_n75));
  nor2 g60(.a(new_n75), .b(new_n45), .O(new_n76));
  nor2 g61(.a(new_n76), .b(new_n29), .O(new_n77));
  inv1 g62(.a(new_n77), .O(dmnst0b));
  nor2 g63(.a(new_n41), .b(new_n23), .O(new_n79));
  inv1 g64(.a(new_n79), .O(new_n80));
  nor2 g65(.a(dmpst2), .b(page), .O(new_n81));
  inv1 g66(.a(new_n81), .O(new_n82));
  nor2 g67(.a(new_n82), .b(new_n62), .O(new_n83));
  inv1 g68(.a(xskip), .O(new_n84));
  nor2 g69(.a(new_n45), .b(new_n84), .O(new_n85));
  nor2 g70(.a(new_n85), .b(new_n83), .O(new_n86));
  inv1 g71(.a(new_n86), .O(new_n87));
  nor2 g72(.a(new_n87), .b(new_n80), .O(new_n88));
  inv1 g73(.a(new_n88), .O(dmnst1b));
  nor2 g74(.a(new_n44), .b(new_n39), .O(new_n90));
  inv1 g75(.a(new_n90), .O(new_n91));
  nor2 g76(.a(new_n91), .b(new_n66), .O(new_n92));
  inv1 g77(.a(new_n92), .O(dmnst2b));
  inv1 g78(.a(new_n51), .O(new_n94));
  nor2 g79(.a(new_n94), .b(new_n33), .O(new_n95));
  nor2 g80(.a(new_n95), .b(new_n27), .O(new_n96));
  inv1 g81(.a(new_n96), .O(dmnst3b));
endmodule


