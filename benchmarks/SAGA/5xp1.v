// Benchmark "top" written by ABC on Tue Nov 26 20:40:41 2024

module top ( 
    i_5_, i_6_, i_3_, i_4_, i_1_, i_2_, i_0_,
    o_1_, o_2_, o_0_, o_9_, o_7_, o_8_, o_5_, o_6_, o_3_, o_4_  );
  input  i_5_, i_6_, i_3_, i_4_, i_1_, i_2_, i_0_;
  output o_1_, o_2_, o_0_, o_9_, o_7_, o_8_, o_5_, o_6_, o_3_, o_4_;
  wire new_n18, new_n19, new_n20, new_n21, new_n22, new_n23, new_n24,
    new_n25, new_n26, new_n27, new_n28, new_n29, new_n30, new_n31, new_n32,
    new_n33, new_n34, new_n35, new_n36, new_n37, new_n38, new_n39, new_n40,
    new_n41, new_n42, new_n43, new_n45, new_n46, new_n47, new_n48, new_n49,
    new_n50, new_n51, new_n52, new_n53, new_n54, new_n55, new_n56, new_n57,
    new_n58, new_n59, new_n60, new_n61, new_n62, new_n63, new_n64, new_n65,
    new_n67, new_n68, new_n69, new_n70, new_n71, new_n72, new_n73, new_n74,
    new_n75, new_n76, new_n77, new_n78, new_n79, new_n80, new_n81, new_n82,
    new_n83, new_n84, new_n85, new_n86, new_n87, new_n88, new_n89, new_n90,
    new_n91, new_n92, new_n93, new_n94, new_n95, new_n96, new_n97, new_n98,
    new_n99, new_n100, new_n101, new_n102, new_n103, new_n104, new_n105,
    new_n106, new_n107, new_n108, new_n109, new_n110, new_n111, new_n112,
    new_n113, new_n114, new_n115, new_n116, new_n117, new_n118, new_n119,
    new_n120, new_n121, new_n122, new_n123, new_n124, new_n125, new_n126,
    new_n127, new_n128, new_n129, new_n130, new_n131, new_n132, new_n133,
    new_n134, new_n135, new_n136, new_n137, new_n138, new_n139, new_n140,
    new_n143, new_n144, new_n145, new_n146, new_n147, new_n150, new_n151,
    new_n152, new_n153, new_n154, new_n156, new_n157, new_n158, new_n159,
    new_n161, new_n162, new_n163, new_n164, new_n165, new_n166, new_n167,
    new_n168, new_n169, new_n170, new_n171, new_n172, new_n173, new_n174,
    new_n175, new_n176, new_n177, new_n178, new_n179, new_n181, new_n182,
    new_n183, new_n184, new_n185, new_n186, new_n187, new_n188, new_n189,
    new_n190, new_n191, new_n192, new_n193, new_n194, new_n195, new_n196,
    new_n197, new_n198, new_n199, new_n200, new_n201, new_n202, new_n203;
  inv1 g000(.a(i_6_), .O(new_n18));
  inv1 g001(.a(i_4_), .O(new_n19));
  nor2 g002(.a(new_n19), .b(i_5_), .O(new_n20));
  inv1 g003(.a(new_n20), .O(new_n21));
  nor2 g004(.a(new_n21), .b(new_n18), .O(new_n22));
  inv1 g005(.a(i_5_), .O(new_n23));
  nor2 g006(.a(i_6_), .b(new_n23), .O(new_n24));
  inv1 g007(.a(new_n24), .O(new_n25));
  nor2 g008(.a(new_n25), .b(i_4_), .O(new_n26));
  nor2 g009(.a(i_0_), .b(i_1_), .O(new_n27));
  inv1 g010(.a(new_n27), .O(new_n28));
  nor2 g011(.a(new_n28), .b(new_n25), .O(new_n29));
  nor2 g012(.a(new_n29), .b(new_n26), .O(new_n30));
  inv1 g013(.a(new_n30), .O(new_n31));
  nor2 g014(.a(new_n31), .b(new_n22), .O(new_n32));
  inv1 g015(.a(new_n32), .O(new_n33));
  nor2 g016(.a(i_2_), .b(i_3_), .O(new_n34));
  inv1 g017(.a(i_1_), .O(new_n35));
  inv1 g018(.a(i_0_), .O(new_n36));
  nor2 g019(.a(new_n36), .b(new_n35), .O(new_n37));
  inv1 g020(.a(new_n37), .O(new_n38));
  nor2 g021(.a(new_n38), .b(new_n34), .O(new_n39));
  inv1 g022(.a(new_n39), .O(new_n40));
  nor2 g023(.a(new_n40), .b(new_n21), .O(new_n41));
  nor2 g024(.a(i_0_), .b(i_6_), .O(new_n42));
  inv1 g025(.a(new_n42), .O(new_n43));
  inv1 g026(.a(i_3_), .O(o_8_));
  inv1 g027(.a(i_2_), .O(new_n45));
  nor2 g028(.a(new_n45), .b(o_8_), .O(new_n46));
  nor2 g029(.a(new_n46), .b(new_n23), .O(new_n47));
  inv1 g030(.a(new_n47), .O(new_n48));
  nor2 g031(.a(new_n48), .b(new_n43), .O(new_n49));
  nor2 g032(.a(new_n49), .b(new_n41), .O(new_n50));
  inv1 g033(.a(new_n50), .O(new_n51));
  nor2 g034(.a(i_2_), .b(i_1_), .O(new_n52));
  nor2 g035(.a(new_n18), .b(i_5_), .O(new_n53));
  inv1 g036(.a(new_n53), .O(new_n54));
  nor2 g037(.a(new_n54), .b(new_n36), .O(new_n55));
  inv1 g038(.a(new_n55), .O(new_n56));
  nor2 g039(.a(new_n56), .b(new_n52), .O(new_n57));
  nor2 g040(.a(new_n28), .b(i_4_), .O(new_n58));
  inv1 g041(.a(new_n58), .O(new_n59));
  nor2 g042(.a(new_n59), .b(new_n48), .O(new_n60));
  nor2 g043(.a(new_n60), .b(new_n57), .O(new_n61));
  inv1 g044(.a(new_n61), .O(new_n62));
  nor2 g045(.a(new_n62), .b(new_n51), .O(new_n63));
  inv1 g046(.a(new_n63), .O(new_n64));
  nor2 g047(.a(new_n64), .b(new_n33), .O(new_n65));
  inv1 g048(.a(new_n65), .O(o_1_));
  nor2 g049(.a(new_n46), .b(new_n28), .O(new_n67));
  inv1 g050(.a(new_n67), .O(new_n68));
  nor2 g051(.a(i_4_), .b(new_n18), .O(new_n69));
  inv1 g052(.a(new_n69), .O(new_n70));
  nor2 g053(.a(new_n70), .b(new_n68), .O(new_n71));
  nor2 g054(.a(new_n35), .b(new_n18), .O(new_n72));
  inv1 g055(.a(new_n72), .O(new_n73));
  nor2 g056(.a(new_n19), .b(new_n23), .O(new_n74));
  inv1 g057(.a(new_n74), .O(new_n75));
  nor2 g058(.a(new_n75), .b(new_n73), .O(new_n76));
  nor2 g059(.a(i_2_), .b(new_n19), .O(new_n77));
  inv1 g060(.a(new_n77), .O(new_n78));
  nor2 g061(.a(new_n78), .b(new_n43), .O(new_n79));
  nor2 g062(.a(new_n79), .b(new_n76), .O(new_n80));
  inv1 g063(.a(new_n80), .O(new_n81));
  nor2 g064(.a(new_n81), .b(new_n71), .O(new_n82));
  inv1 g065(.a(new_n82), .O(new_n83));
  inv1 g066(.a(new_n34), .O(new_n84));
  nor2 g067(.a(i_6_), .b(i_5_), .O(new_n85));
  inv1 g068(.a(new_n85), .O(new_n86));
  nor2 g069(.a(new_n86), .b(new_n84), .O(new_n87));
  inv1 g070(.a(new_n87), .O(new_n88));
  nor2 g071(.a(new_n88), .b(new_n19), .O(new_n89));
  inv1 g072(.a(new_n46), .O(new_n90));
  nor2 g073(.a(new_n90), .b(new_n28), .O(new_n91));
  inv1 g074(.a(new_n91), .O(new_n92));
  nor2 g075(.a(new_n92), .b(new_n75), .O(new_n93));
  nor2 g076(.a(new_n93), .b(new_n89), .O(new_n94));
  inv1 g077(.a(new_n94), .O(new_n95));
  nor2 g078(.a(new_n95), .b(new_n83), .O(new_n96));
  inv1 g079(.a(new_n96), .O(new_n97));
  nor2 g080(.a(new_n18), .b(new_n23), .O(new_n98));
  inv1 g081(.a(new_n98), .O(new_n99));
  nor2 g082(.a(new_n99), .b(new_n36), .O(new_n100));
  nor2 g083(.a(new_n86), .b(new_n37), .O(new_n101));
  nor2 g084(.a(new_n101), .b(new_n100), .O(new_n102));
  nor2 g085(.a(new_n102), .b(new_n19), .O(new_n103));
  nor2 g086(.a(new_n36), .b(new_n19), .O(new_n104));
  inv1 g087(.a(new_n104), .O(new_n105));
  nor2 g088(.a(new_n105), .b(new_n73), .O(new_n106));
  nor2 g089(.a(new_n19), .b(i_3_), .O(new_n107));
  inv1 g090(.a(new_n107), .O(new_n108));
  nor2 g091(.a(new_n108), .b(new_n43), .O(new_n109));
  nor2 g092(.a(new_n109), .b(new_n106), .O(new_n110));
  inv1 g093(.a(new_n110), .O(new_n111));
  nor2 g094(.a(i_0_), .b(i_5_), .O(new_n112));
  inv1 g095(.a(new_n112), .O(new_n113));
  nor2 g096(.a(new_n113), .b(new_n70), .O(new_n114));
  nor2 g097(.a(new_n45), .b(new_n18), .O(new_n115));
  inv1 g098(.a(new_n115), .O(new_n116));
  nor2 g099(.a(new_n116), .b(new_n105), .O(new_n117));
  nor2 g100(.a(new_n117), .b(new_n114), .O(new_n118));
  inv1 g101(.a(new_n118), .O(new_n119));
  nor2 g102(.a(new_n119), .b(new_n111), .O(new_n120));
  inv1 g103(.a(new_n120), .O(new_n121));
  nor2 g104(.a(new_n121), .b(new_n103), .O(new_n122));
  inv1 g105(.a(new_n122), .O(new_n123));
  nor2 g106(.a(new_n123), .b(new_n97), .O(new_n124));
  inv1 g107(.a(new_n124), .O(new_n125));
  inv1 g108(.a(new_n26), .O(new_n126));
  nor2 g109(.a(new_n113), .b(new_n73), .O(new_n127));
  nor2 g110(.a(new_n127), .b(new_n29), .O(new_n128));
  inv1 g111(.a(new_n128), .O(new_n129));
  nor2 g112(.a(new_n129), .b(new_n49), .O(new_n130));
  inv1 g113(.a(new_n130), .O(new_n131));
  nor2 g114(.a(new_n131), .b(new_n126), .O(new_n132));
  nor2 g115(.a(new_n40), .b(i_6_), .O(new_n133));
  inv1 g116(.a(new_n52), .O(new_n134));
  nor2 g117(.a(new_n54), .b(new_n134), .O(new_n135));
  nor2 g118(.a(new_n135), .b(new_n133), .O(new_n136));
  nor2 g119(.a(new_n136), .b(i_4_), .O(new_n137));
  nor2 g120(.a(new_n137), .b(new_n132), .O(new_n138));
  inv1 g121(.a(new_n138), .O(new_n139));
  nor2 g122(.a(new_n139), .b(new_n125), .O(new_n140));
  inv1 g123(.a(new_n140), .O(o_2_));
  nor2 g124(.a(new_n131), .b(new_n75), .O(o_9_));
  nor2 g125(.a(o_9_), .b(new_n19), .O(new_n143));
  nor2 g126(.a(new_n70), .b(new_n23), .O(new_n144));
  inv1 g127(.a(new_n144), .O(new_n145));
  nor2 g128(.a(new_n145), .b(new_n67), .O(new_n146));
  nor2 g129(.a(new_n146), .b(new_n143), .O(new_n147));
  inv1 g130(.a(new_n147), .O(o_0_));
  nor2 g131(.a(new_n46), .b(new_n34), .O(o_7_));
  inv1 g132(.a(o_7_), .O(new_n150));
  nor2 g133(.a(new_n150), .b(new_n52), .O(new_n151));
  nor2 g134(.a(new_n151), .b(i_0_), .O(new_n152));
  inv1 g135(.a(new_n151), .O(new_n153));
  nor2 g136(.a(new_n153), .b(new_n36), .O(new_n154));
  nor2 g137(.a(new_n154), .b(new_n152), .O(o_5_));
  nor2 g138(.a(i_2_), .b(o_8_), .O(new_n156));
  inv1 g139(.a(new_n156), .O(new_n157));
  nor2 g140(.a(new_n157), .b(new_n35), .O(new_n158));
  nor2 g141(.a(new_n156), .b(i_1_), .O(new_n159));
  nor2 g142(.a(new_n159), .b(new_n158), .O(o_6_));
  nor2 g143(.a(new_n36), .b(i_1_), .O(new_n161));
  inv1 g144(.a(new_n161), .O(new_n162));
  nor2 g145(.a(new_n162), .b(new_n115), .O(new_n163));
  nor2 g146(.a(i_1_), .b(i_6_), .O(new_n164));
  nor2 g147(.a(new_n90), .b(i_0_), .O(new_n165));
  inv1 g148(.a(new_n165), .O(new_n166));
  nor2 g149(.a(new_n166), .b(new_n164), .O(new_n167));
  nor2 g150(.a(new_n167), .b(new_n163), .O(new_n168));
  nor2 g151(.a(new_n168), .b(i_5_), .O(new_n169));
  nor2 g152(.a(new_n67), .b(new_n39), .O(new_n170));
  nor2 g153(.a(new_n170), .b(new_n23), .O(new_n171));
  nor2 g154(.a(new_n99), .b(new_n52), .O(new_n172));
  nor2 g155(.a(new_n172), .b(new_n87), .O(new_n173));
  nor2 g156(.a(new_n173), .b(new_n36), .O(new_n174));
  nor2 g157(.a(new_n174), .b(new_n131), .O(new_n175));
  inv1 g158(.a(new_n175), .O(new_n176));
  nor2 g159(.a(new_n176), .b(new_n171), .O(new_n177));
  inv1 g160(.a(new_n177), .O(new_n178));
  nor2 g161(.a(new_n178), .b(new_n169), .O(new_n179));
  inv1 g162(.a(new_n179), .O(o_3_));
  nor2 g163(.a(new_n28), .b(i_3_), .O(new_n181));
  nor2 g164(.a(new_n90), .b(new_n35), .O(new_n182));
  nor2 g165(.a(new_n182), .b(new_n39), .O(new_n183));
  inv1 g166(.a(new_n183), .O(new_n184));
  nor2 g167(.a(new_n184), .b(new_n181), .O(new_n185));
  nor2 g168(.a(new_n185), .b(new_n18), .O(new_n186));
  inv1 g169(.a(new_n164), .O(new_n187));
  nor2 g170(.a(new_n187), .b(new_n45), .O(new_n188));
  inv1 g171(.a(new_n188), .O(new_n189));
  nor2 g172(.a(new_n189), .b(new_n67), .O(new_n190));
  nor2 g173(.a(new_n43), .b(new_n35), .O(new_n191));
  inv1 g174(.a(new_n191), .O(new_n192));
  nor2 g175(.a(new_n192), .b(new_n46), .O(new_n193));
  nor2 g176(.a(new_n35), .b(i_3_), .O(new_n194));
  nor2 g177(.a(new_n194), .b(i_6_), .O(new_n195));
  nor2 g178(.a(new_n72), .b(i_2_), .O(new_n196));
  inv1 g179(.a(new_n196), .O(new_n197));
  nor2 g180(.a(new_n197), .b(new_n195), .O(new_n198));
  nor2 g181(.a(new_n198), .b(new_n193), .O(new_n199));
  inv1 g182(.a(new_n199), .O(new_n200));
  nor2 g183(.a(new_n200), .b(new_n190), .O(new_n201));
  inv1 g184(.a(new_n201), .O(new_n202));
  nor2 g185(.a(new_n202), .b(new_n186), .O(new_n203));
  inv1 g186(.a(new_n203), .O(o_4_));
endmodule


