// Benchmark "top" written by ABC on Tue Nov 12 20:12:16 2024

module top ( 
    \opcode[0] , \opcode[1] , \opcode[2] , \opcode[3] , \opcode[4] ,
    \op_ext[0] , \op_ext[1] ,
    \sel_reg_dst[0] , \sel_reg_dst[1] , \sel_alu_opB[0] , \sel_alu_opB[1] ,
    \alu_op[0] , \alu_op[1] , \alu_op[2] , \alu_op_ext[0] ,
    \alu_op_ext[1] , \alu_op_ext[2] , \alu_op_ext[3] , halt, reg_write,
    sel_pc_opA, sel_pc_opB, beqz, bnez, bgez, bltz, jump, Cin, invA, invB,
    sign, mem_write, sel_wb  );
  input  \opcode[0] , \opcode[1] , \opcode[2] , \opcode[3] , \opcode[4] ,
    \op_ext[0] , \op_ext[1] ;
  output \sel_reg_dst[0] , \sel_reg_dst[1] , \sel_alu_opB[0] ,
    \sel_alu_opB[1] , \alu_op[0] , \alu_op[1] , \alu_op[2] ,
    \alu_op_ext[0] , \alu_op_ext[1] , \alu_op_ext[2] , \alu_op_ext[3] ,
    halt, reg_write, sel_pc_opA, sel_pc_opB, beqz, bnez, bgez, bltz, jump,
    Cin, invA, invB, sign, mem_write, sel_wb;
  wire new_n34, new_n35, new_n36, new_n37, new_n38, new_n39, new_n40,
    new_n41, new_n42, new_n43, new_n44, new_n45, new_n46, new_n47, new_n48,
    new_n49, new_n50, new_n51, new_n52, new_n53, new_n54, new_n55, new_n56,
    new_n58, new_n59, new_n61, new_n62, new_n63, new_n64, new_n65, new_n66,
    new_n67, new_n69, new_n70, new_n71, new_n72, new_n73, new_n74, new_n75,
    new_n76, new_n77, new_n79, new_n80, new_n81, new_n82, new_n83, new_n84,
    new_n85, new_n86, new_n87, new_n88, new_n89, new_n90, new_n91, new_n92,
    new_n93, new_n94, new_n95, new_n96, new_n98, new_n99, new_n100,
    new_n102, new_n103, new_n104, new_n105, new_n106, new_n107, new_n108,
    new_n109, new_n110, new_n112, new_n113, new_n114, new_n115, new_n116,
    new_n117, new_n119, new_n120, new_n121, new_n122, new_n123, new_n126,
    new_n128, new_n129, new_n130, new_n133, new_n134, new_n136, new_n138,
    new_n139, new_n140, new_n142, new_n143, new_n145, new_n146, new_n147,
    new_n151, new_n152, new_n153, new_n154, new_n155, new_n156, new_n158,
    new_n160, new_n163, new_n164, new_n166, new_n167;
  inv1 g000(.a(\opcode[2] ), .O(new_n34));
  inv1 g001(.a(\opcode[1] ), .O(new_n35));
  nor2 g002(.a(\opcode[4] ), .b(\opcode[3] ), .O(new_n36));
  inv1 g003(.a(new_n36), .O(new_n37));
  nor2 g004(.a(new_n37), .b(new_n35), .O(new_n38));
  nor2 g005(.a(new_n38), .b(\opcode[4] ), .O(new_n39));
  nor2 g006(.a(new_n39), .b(new_n34), .O(new_n40));
  nor2 g007(.a(\opcode[1] ), .b(\opcode[0] ), .O(new_n41));
  inv1 g008(.a(\opcode[4] ), .O(new_n42));
  nor2 g009(.a(new_n42), .b(\opcode[2] ), .O(new_n43));
  inv1 g010(.a(new_n43), .O(new_n44));
  nor2 g011(.a(new_n44), .b(new_n41), .O(new_n45));
  inv1 g012(.a(\opcode[3] ), .O(new_n46));
  nor2 g013(.a(new_n46), .b(\opcode[2] ), .O(new_n47));
  nor2 g014(.a(new_n47), .b(new_n45), .O(new_n48));
  inv1 g015(.a(new_n48), .O(new_n49));
  nor2 g016(.a(new_n49), .b(new_n40), .O(new_n50));
  nor2 g017(.a(new_n46), .b(\opcode[0] ), .O(new_n51));
  nor2 g018(.a(new_n42), .b(new_n46), .O(new_n52));
  nor2 g019(.a(new_n52), .b(new_n36), .O(new_n53));
  nor2 g020(.a(new_n53), .b(new_n51), .O(new_n54));
  nor2 g021(.a(\opcode[2] ), .b(\opcode[1] ), .O(new_n55));
  nor2 g022(.a(new_n55), .b(new_n46), .O(new_n56));
  nor2 g023(.a(new_n56), .b(new_n54), .O(\sel_alu_opB[1] ));
  nor2 g024(.a(\sel_alu_opB[1] ), .b(new_n39), .O(new_n58));
  inv1 g025(.a(new_n58), .O(new_n59));
  nor2 g026(.a(new_n59), .b(new_n50), .O(\sel_reg_dst[0] ));
  inv1 g027(.a(\sel_alu_opB[1] ), .O(new_n61));
  inv1 g028(.a(new_n51), .O(new_n62));
  nor2 g029(.a(new_n62), .b(new_n42), .O(new_n63));
  nor2 g030(.a(new_n63), .b(\opcode[1] ), .O(new_n64));
  nor2 g031(.a(new_n64), .b(new_n61), .O(new_n65));
  nor2 g032(.a(new_n65), .b(\opcode[2] ), .O(new_n66));
  nor2 g033(.a(new_n38), .b(new_n34), .O(new_n67));
  nor2 g034(.a(new_n67), .b(new_n66), .O(\sel_reg_dst[1] ));
  nor2 g035(.a(new_n42), .b(\opcode[3] ), .O(new_n69));
  inv1 g036(.a(new_n69), .O(new_n70));
  nor2 g037(.a(new_n70), .b(\opcode[0] ), .O(new_n71));
  nor2 g038(.a(new_n71), .b(new_n35), .O(new_n72));
  inv1 g039(.a(new_n72), .O(new_n73));
  nor2 g040(.a(\opcode[4] ), .b(new_n46), .O(new_n74));
  nor2 g041(.a(new_n74), .b(new_n73), .O(new_n75));
  nor2 g042(.a(new_n64), .b(\opcode[2] ), .O(new_n76));
  inv1 g043(.a(new_n76), .O(new_n77));
  nor2 g044(.a(new_n77), .b(new_n75), .O(\sel_alu_opB[0] ));
  nor2 g045(.a(\op_ext[1] ), .b(new_n42), .O(new_n79));
  nor2 g046(.a(new_n79), .b(new_n46), .O(new_n80));
  inv1 g047(.a(new_n80), .O(new_n81));
  inv1 g048(.a(\opcode[0] ), .O(new_n82));
  nor2 g049(.a(\op_ext[0] ), .b(new_n42), .O(new_n83));
  nor2 g050(.a(new_n83), .b(new_n82), .O(new_n84));
  inv1 g051(.a(new_n84), .O(new_n85));
  nor2 g052(.a(new_n85), .b(new_n81), .O(new_n86));
  inv1 g053(.a(\op_ext[0] ), .O(new_n87));
  inv1 g054(.a(new_n63), .O(new_n88));
  nor2 g055(.a(new_n88), .b(new_n87), .O(new_n89));
  nor2 g056(.a(new_n89), .b(new_n86), .O(new_n90));
  nor2 g057(.a(new_n90), .b(new_n35), .O(new_n91));
  nor2 g058(.a(new_n91), .b(\opcode[2] ), .O(new_n92));
  nor2 g059(.a(new_n69), .b(new_n34), .O(new_n93));
  nor2 g060(.a(new_n34), .b(\opcode[0] ), .O(new_n94));
  nor2 g061(.a(new_n94), .b(new_n93), .O(new_n95));
  inv1 g062(.a(new_n95), .O(new_n96));
  nor2 g063(.a(new_n96), .b(new_n92), .O(\alu_op[0] ));
  nor2 g064(.a(new_n80), .b(\opcode[2] ), .O(new_n98));
  nor2 g065(.a(new_n93), .b(new_n35), .O(new_n99));
  inv1 g066(.a(new_n99), .O(new_n100));
  nor2 g067(.a(new_n100), .b(new_n98), .O(\alu_op[1] ));
  inv1 g068(.a(new_n53), .O(new_n102));
  nor2 g069(.a(new_n102), .b(new_n34), .O(new_n103));
  inv1 g070(.a(new_n52), .O(new_n104));
  nor2 g071(.a(new_n35), .b(new_n82), .O(new_n105));
  nor2 g072(.a(new_n105), .b(new_n104), .O(new_n106));
  inv1 g073(.a(new_n106), .O(new_n107));
  nor2 g074(.a(new_n107), .b(\opcode[2] ), .O(new_n108));
  nor2 g075(.a(new_n108), .b(new_n36), .O(new_n109));
  inv1 g076(.a(new_n109), .O(new_n110));
  nor2 g077(.a(new_n110), .b(new_n103), .O(\alu_op[2] ));
  inv1 g078(.a(new_n55), .O(new_n112));
  nor2 g079(.a(new_n88), .b(new_n112), .O(new_n113));
  inv1 g080(.a(new_n40), .O(new_n114));
  inv1 g081(.a(new_n54), .O(new_n115));
  nor2 g082(.a(new_n115), .b(new_n114), .O(new_n116));
  nor2 g083(.a(new_n116), .b(new_n113), .O(new_n117));
  inv1 g084(.a(new_n117), .O(\alu_op_ext[0] ));
  nor2 g085(.a(new_n52), .b(\opcode[1] ), .O(new_n119));
  nor2 g086(.a(new_n119), .b(new_n72), .O(new_n120));
  nor2 g087(.a(new_n120), .b(\opcode[2] ), .O(new_n121));
  nor2 g088(.a(new_n103), .b(new_n35), .O(new_n122));
  inv1 g089(.a(new_n122), .O(new_n123));
  nor2 g090(.a(new_n123), .b(new_n121), .O(\alu_op_ext[1] ));
  nor2 g091(.a(new_n121), .b(new_n67), .O(\alu_op_ext[2] ));
  nor2 g092(.a(new_n69), .b(new_n47), .O(new_n126));
  nor2 g093(.a(new_n126), .b(\alu_op_ext[2] ), .O(\alu_op_ext[3] ));
  inv1 g094(.a(new_n41), .O(new_n128));
  nor2 g095(.a(new_n37), .b(\opcode[2] ), .O(new_n129));
  inv1 g096(.a(new_n129), .O(new_n130));
  nor2 g097(.a(new_n130), .b(new_n128), .O(halt));
  inv1 g098(.a(new_n50), .O(reg_write));
  nor2 g099(.a(new_n34), .b(new_n82), .O(new_n133));
  inv1 g100(.a(new_n133), .O(new_n134));
  nor2 g101(.a(new_n134), .b(new_n37), .O(sel_pc_opA));
  inv1 g102(.a(new_n94), .O(new_n136));
  nor2 g103(.a(new_n136), .b(new_n37), .O(sel_pc_opB));
  inv1 g104(.a(new_n119), .O(new_n138));
  nor2 g105(.a(new_n138), .b(new_n46), .O(new_n139));
  inv1 g106(.a(new_n139), .O(new_n140));
  nor2 g107(.a(new_n140), .b(new_n136), .O(beqz));
  nor2 g108(.a(new_n140), .b(new_n82), .O(new_n142));
  inv1 g109(.a(new_n142), .O(new_n143));
  nor2 g110(.a(new_n143), .b(new_n34), .O(bnez));
  inv1 g111(.a(new_n74), .O(new_n145));
  nor2 g112(.a(new_n145), .b(new_n35), .O(new_n146));
  inv1 g113(.a(new_n146), .O(new_n147));
  nor2 g114(.a(new_n147), .b(new_n134), .O(bgez));
  nor2 g115(.a(new_n147), .b(new_n136), .O(bltz));
  nor2 g116(.a(new_n37), .b(new_n34), .O(jump));
  nor2 g117(.a(new_n106), .b(new_n34), .O(new_n151));
  inv1 g118(.a(new_n56), .O(new_n152));
  nor2 g119(.a(new_n85), .b(new_n152), .O(new_n153));
  nor2 g120(.a(new_n153), .b(\opcode[2] ), .O(new_n154));
  inv1 g121(.a(new_n154), .O(new_n155));
  nor2 g122(.a(new_n155), .b(new_n142), .O(new_n156));
  nor2 g123(.a(new_n156), .b(new_n151), .O(Cin));
  nor2 g124(.a(new_n154), .b(new_n98), .O(new_n158));
  nor2 g125(.a(new_n158), .b(new_n156), .O(invA));
  inv1 g126(.a(new_n158), .O(new_n160));
  nor2 g127(.a(new_n160), .b(new_n151), .O(invB));
  inv1 g128(.a(new_n121), .O(new_n163));
  inv1 g129(.a(new_n45), .O(new_n164));
  nor2 g130(.a(new_n138), .b(new_n164), .O(sel_wb));
  nor2 g131(.a(sel_wb), .b(new_n70), .O(new_n166));
  inv1 g132(.a(new_n166), .O(new_n167));
  nor2 g133(.a(new_n167), .b(new_n163), .O(mem_write));
  one  g134(.O(sign));
endmodule


