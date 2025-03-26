// Benchmark "top" written by ABC on Tue Nov 12 20:12:26 2024

module top ( 
    \dest_x[0] , \dest_x[1] , \dest_x[2] , \dest_x[3] , \dest_x[4] ,
    \dest_x[5] , \dest_x[6] , \dest_x[7] , \dest_x[8] , \dest_x[9] ,
    \dest_x[10] , \dest_x[11] , \dest_x[12] , \dest_x[13] , \dest_x[14] ,
    \dest_x[15] , \dest_x[16] , \dest_x[17] , \dest_x[18] , \dest_x[19] ,
    \dest_x[20] , \dest_x[21] , \dest_x[22] , \dest_x[23] , \dest_x[24] ,
    \dest_x[25] , \dest_x[26] , \dest_x[27] , \dest_x[28] , \dest_x[29] ,
    \dest_y[0] , \dest_y[1] , \dest_y[2] , \dest_y[3] , \dest_y[4] ,
    \dest_y[5] , \dest_y[6] , \dest_y[7] , \dest_y[8] , \dest_y[9] ,
    \dest_y[10] , \dest_y[11] , \dest_y[12] , \dest_y[13] , \dest_y[14] ,
    \dest_y[15] , \dest_y[16] , \dest_y[17] , \dest_y[18] , \dest_y[19] ,
    \dest_y[20] , \dest_y[21] , \dest_y[22] , \dest_y[23] , \dest_y[24] ,
    \dest_y[25] , \dest_y[26] , \dest_y[27] , \dest_y[28] , \dest_y[29] ,
    \outport[0] , \outport[1] , \outport[2] , \outport[3] , \outport[4] ,
    \outport[5] , \outport[6] , \outport[7] , \outport[8] , \outport[9] ,
    \outport[10] , \outport[11] , \outport[12] , \outport[13] ,
    \outport[14] , \outport[15] , \outport[16] , \outport[17] ,
    \outport[18] , \outport[19] , \outport[20] , \outport[21] ,
    \outport[22] , \outport[23] , \outport[24] , \outport[25] ,
    \outport[26] , \outport[27] , \outport[28] , \outport[29]   );
  input  \dest_x[0] , \dest_x[1] , \dest_x[2] , \dest_x[3] , \dest_x[4] ,
    \dest_x[5] , \dest_x[6] , \dest_x[7] , \dest_x[8] , \dest_x[9] ,
    \dest_x[10] , \dest_x[11] , \dest_x[12] , \dest_x[13] , \dest_x[14] ,
    \dest_x[15] , \dest_x[16] , \dest_x[17] , \dest_x[18] , \dest_x[19] ,
    \dest_x[20] , \dest_x[21] , \dest_x[22] , \dest_x[23] , \dest_x[24] ,
    \dest_x[25] , \dest_x[26] , \dest_x[27] , \dest_x[28] , \dest_x[29] ,
    \dest_y[0] , \dest_y[1] , \dest_y[2] , \dest_y[3] , \dest_y[4] ,
    \dest_y[5] , \dest_y[6] , \dest_y[7] , \dest_y[8] , \dest_y[9] ,
    \dest_y[10] , \dest_y[11] , \dest_y[12] , \dest_y[13] , \dest_y[14] ,
    \dest_y[15] , \dest_y[16] , \dest_y[17] , \dest_y[18] , \dest_y[19] ,
    \dest_y[20] , \dest_y[21] , \dest_y[22] , \dest_y[23] , \dest_y[24] ,
    \dest_y[25] , \dest_y[26] , \dest_y[27] , \dest_y[28] , \dest_y[29] ;
  output \outport[0] , \outport[1] , \outport[2] , \outport[3] , \outport[4] ,
    \outport[5] , \outport[6] , \outport[7] , \outport[8] , \outport[9] ,
    \outport[10] , \outport[11] , \outport[12] , \outport[13] ,
    \outport[14] , \outport[15] , \outport[16] , \outport[17] ,
    \outport[18] , \outport[19] , \outport[20] , \outport[21] ,
    \outport[22] , \outport[23] , \outport[24] , \outport[25] ,
    \outport[26] , \outport[27] , \outport[28] , \outport[29] ;
  wire new_n91, new_n92, new_n93, new_n94, new_n95, new_n96, new_n97,
    new_n98, new_n99, new_n100, new_n101, new_n102, new_n103, new_n104,
    new_n105, new_n106, new_n107, new_n108, new_n109, new_n110, new_n111,
    new_n112, new_n113, new_n114, new_n115, new_n116, new_n117, new_n118,
    new_n119, new_n120, new_n121, new_n122, new_n123, new_n124, new_n125,
    new_n126, new_n127, new_n128, new_n129, new_n130, new_n131, new_n132,
    new_n133, new_n134, new_n135, new_n136, new_n137, new_n138, new_n139,
    new_n140, new_n141, new_n142, new_n143, new_n144, new_n145, new_n146,
    new_n147, new_n148, new_n149, new_n150, new_n151, new_n152, new_n153,
    new_n154, new_n155, new_n156, new_n157, new_n158, new_n159, new_n160,
    new_n161, new_n162, new_n163, new_n164, new_n165, new_n166, new_n167,
    new_n168, new_n169, new_n170, new_n171, new_n172, new_n173, new_n174,
    new_n175, new_n176, new_n177, new_n178, new_n179, new_n180, new_n181,
    new_n182, new_n183, new_n184, new_n185, new_n186, new_n187, new_n188,
    new_n189, new_n190, new_n191, new_n192, new_n193, new_n194, new_n195,
    new_n196, new_n197, new_n198, new_n199, new_n200, new_n201, new_n202,
    new_n203, new_n204, new_n205, new_n206, new_n207, new_n208, new_n209,
    new_n210, new_n211, new_n212, new_n213, new_n214, new_n215, new_n216,
    new_n217, new_n218, new_n219, new_n220, new_n221, new_n222, new_n223,
    new_n224, new_n225, new_n226, new_n227, new_n228, new_n229, new_n230,
    new_n231, new_n232, new_n233, new_n234, new_n235, new_n236, new_n237,
    new_n238, new_n239, new_n240, new_n242, new_n243, new_n244, new_n245,
    new_n246, new_n247, new_n248, new_n249, new_n250, new_n251, new_n252,
    new_n253, new_n254, new_n255, new_n256, new_n257, new_n258, new_n259,
    new_n260, new_n261, new_n262, new_n263, new_n264, new_n265, new_n266,
    new_n267, new_n268, new_n269, new_n270, new_n271, new_n272, new_n273,
    new_n274, new_n275, new_n276, new_n277, new_n278, new_n279, new_n280,
    new_n281, new_n282, new_n283, new_n284, new_n285, new_n286, new_n287,
    new_n288, new_n289, new_n290, new_n291, new_n292, new_n293, new_n294,
    new_n295, new_n296, new_n297, new_n298, new_n299, new_n300, new_n301,
    new_n302, new_n303, new_n304, new_n305, new_n306, new_n307, new_n308,
    new_n309, new_n310, new_n311, new_n312, new_n313, new_n314, new_n315,
    new_n316, new_n317, new_n318, new_n319, new_n320, new_n321, new_n322,
    new_n323, new_n324, new_n325, new_n326, new_n327, new_n328, new_n329,
    new_n330, new_n331, new_n332, new_n333, new_n334, new_n335, new_n336,
    new_n337, new_n338, new_n339, new_n340, new_n341, new_n342, new_n343,
    new_n344, new_n345, new_n346, new_n347, new_n348, new_n349, new_n350,
    new_n351, new_n352, new_n353, new_n354, new_n355, new_n356, new_n357,
    new_n358, new_n359, new_n360, new_n361, new_n362, new_n363, new_n364,
    new_n365, new_n366, new_n367, new_n368, new_n369, new_n370, new_n371,
    new_n372, new_n373, new_n374, new_n375, new_n376, new_n377, new_n378,
    new_n379, new_n380, new_n381, new_n382, new_n383, new_n384, new_n385,
    new_n386, new_n387, new_n388, new_n389, new_n390, new_n391, new_n392,
    new_n393, new_n394, new_n395, new_n396, new_n397, new_n398, new_n399,
    new_n400, new_n401, new_n402, new_n403, new_n404, new_n405, new_n406,
    new_n407, new_n408, new_n409, new_n410, new_n411, new_n412, new_n413,
    new_n414, new_n415, new_n416, new_n417, new_n418, new_n420, new_n421,
    new_n422, new_n423, new_n424, new_n425, new_n426, new_n427;
  inv1 g000(.a(\dest_x[23] ), .O(new_n91));
  inv1 g001(.a(\dest_x[20] ), .O(new_n92));
  inv1 g002(.a(\dest_x[19] ), .O(new_n93));
  inv1 g003(.a(\dest_x[15] ), .O(new_n94));
  inv1 g004(.a(\dest_x[14] ), .O(new_n95));
  inv1 g005(.a(\dest_x[11] ), .O(new_n96));
  nor2 g006(.a(\dest_x[10] ), .b(\dest_x[9] ), .O(new_n97));
  nor2 g007(.a(new_n97), .b(new_n96), .O(new_n98));
  nor2 g008(.a(new_n98), .b(\dest_x[12] ), .O(new_n99));
  inv1 g009(.a(new_n99), .O(new_n100));
  nor2 g010(.a(new_n100), .b(\dest_x[13] ), .O(new_n101));
  nor2 g011(.a(new_n101), .b(new_n95), .O(new_n102));
  inv1 g012(.a(new_n102), .O(new_n103));
  nor2 g013(.a(new_n103), .b(new_n94), .O(new_n104));
  nor2 g014(.a(new_n104), .b(\dest_x[16] ), .O(new_n105));
  inv1 g015(.a(\dest_x[17] ), .O(new_n106));
  nor2 g016(.a(\dest_x[18] ), .b(new_n106), .O(new_n107));
  inv1 g017(.a(new_n107), .O(new_n108));
  nor2 g018(.a(new_n108), .b(new_n105), .O(new_n109));
  nor2 g019(.a(new_n109), .b(\dest_x[18] ), .O(new_n110));
  nor2 g020(.a(new_n110), .b(new_n93), .O(new_n111));
  inv1 g021(.a(new_n111), .O(new_n112));
  nor2 g022(.a(new_n112), .b(new_n92), .O(new_n113));
  nor2 g023(.a(new_n113), .b(\dest_x[21] ), .O(new_n114));
  inv1 g024(.a(new_n114), .O(new_n115));
  nor2 g025(.a(new_n115), .b(\dest_x[22] ), .O(new_n116));
  nor2 g026(.a(new_n116), .b(new_n91), .O(new_n117));
  inv1 g027(.a(new_n117), .O(new_n118));
  inv1 g028(.a(\dest_x[24] ), .O(new_n119));
  inv1 g029(.a(\dest_x[25] ), .O(new_n120));
  nor2 g030(.a(new_n120), .b(new_n119), .O(new_n121));
  inv1 g031(.a(new_n121), .O(new_n122));
  nor2 g032(.a(new_n122), .b(new_n118), .O(new_n123));
  nor2 g033(.a(new_n123), .b(\dest_x[26] ), .O(new_n124));
  inv1 g034(.a(\dest_x[29] ), .O(new_n125));
  inv1 g035(.a(\dest_x[27] ), .O(new_n126));
  inv1 g036(.a(\dest_x[28] ), .O(new_n127));
  nor2 g037(.a(new_n127), .b(new_n126), .O(new_n128));
  inv1 g038(.a(new_n128), .O(new_n129));
  nor2 g039(.a(new_n129), .b(new_n125), .O(new_n130));
  inv1 g040(.a(new_n130), .O(new_n131));
  nor2 g041(.a(new_n131), .b(new_n124), .O(new_n132));
  inv1 g042(.a(\dest_x[22] ), .O(new_n133));
  nor2 g043(.a(new_n114), .b(new_n133), .O(new_n134));
  nor2 g044(.a(new_n134), .b(\dest_x[23] ), .O(new_n135));
  inv1 g045(.a(new_n105), .O(new_n136));
  inv1 g046(.a(\dest_x[13] ), .O(new_n137));
  nor2 g047(.a(new_n99), .b(new_n137), .O(new_n138));
  nor2 g048(.a(new_n138), .b(\dest_x[14] ), .O(new_n139));
  nor2 g049(.a(new_n94), .b(\dest_x[12] ), .O(new_n140));
  inv1 g050(.a(new_n140), .O(new_n141));
  nor2 g051(.a(\dest_x[26] ), .b(new_n93), .O(new_n142));
  inv1 g052(.a(new_n142), .O(new_n143));
  nor2 g053(.a(new_n143), .b(new_n141), .O(new_n144));
  inv1 g054(.a(new_n144), .O(new_n145));
  inv1 g055(.a(\dest_x[6] ), .O(new_n146));
  inv1 g056(.a(\dest_x[7] ), .O(new_n147));
  nor2 g057(.a(new_n147), .b(new_n146), .O(new_n148));
  inv1 g058(.a(new_n148), .O(new_n149));
  inv1 g059(.a(\dest_x[8] ), .O(new_n150));
  nor2 g060(.a(new_n96), .b(new_n150), .O(new_n151));
  inv1 g061(.a(new_n151), .O(new_n152));
  nor2 g062(.a(new_n152), .b(new_n149), .O(new_n153));
  inv1 g063(.a(new_n153), .O(new_n154));
  nor2 g064(.a(new_n154), .b(new_n145), .O(new_n155));
  inv1 g065(.a(new_n155), .O(new_n156));
  nor2 g066(.a(new_n156), .b(new_n131), .O(new_n157));
  inv1 g067(.a(new_n157), .O(new_n158));
  nor2 g068(.a(\dest_x[21] ), .b(new_n92), .O(new_n159));
  inv1 g069(.a(new_n159), .O(new_n160));
  nor2 g070(.a(new_n122), .b(new_n108), .O(new_n161));
  inv1 g071(.a(new_n161), .O(new_n162));
  nor2 g072(.a(new_n162), .b(new_n160), .O(new_n163));
  inv1 g073(.a(new_n163), .O(new_n164));
  inv1 g074(.a(\dest_x[2] ), .O(new_n165));
  inv1 g075(.a(\dest_x[3] ), .O(new_n166));
  nor2 g076(.a(new_n166), .b(new_n165), .O(new_n167));
  inv1 g077(.a(new_n167), .O(new_n168));
  inv1 g078(.a(\dest_x[4] ), .O(new_n169));
  inv1 g079(.a(\dest_x[5] ), .O(new_n170));
  nor2 g080(.a(new_n170), .b(new_n169), .O(new_n171));
  inv1 g081(.a(new_n171), .O(new_n172));
  nor2 g082(.a(new_n172), .b(new_n168), .O(new_n173));
  inv1 g083(.a(new_n173), .O(new_n174));
  inv1 g084(.a(new_n97), .O(new_n175));
  inv1 g085(.a(\dest_x[0] ), .O(new_n176));
  inv1 g086(.a(\dest_x[1] ), .O(new_n177));
  nor2 g087(.a(new_n177), .b(new_n176), .O(new_n178));
  inv1 g088(.a(new_n178), .O(new_n179));
  nor2 g089(.a(new_n179), .b(new_n175), .O(new_n180));
  inv1 g090(.a(new_n180), .O(new_n181));
  nor2 g091(.a(new_n181), .b(new_n174), .O(new_n182));
  inv1 g092(.a(new_n182), .O(new_n183));
  nor2 g093(.a(new_n183), .b(new_n164), .O(new_n184));
  inv1 g094(.a(new_n184), .O(new_n185));
  nor2 g095(.a(new_n185), .b(new_n158), .O(new_n186));
  inv1 g096(.a(new_n186), .O(new_n187));
  nor2 g097(.a(new_n187), .b(new_n102), .O(new_n188));
  inv1 g098(.a(new_n188), .O(new_n189));
  nor2 g099(.a(new_n189), .b(new_n139), .O(new_n190));
  inv1 g100(.a(new_n190), .O(new_n191));
  nor2 g101(.a(new_n191), .b(new_n136), .O(new_n192));
  inv1 g102(.a(new_n192), .O(new_n193));
  nor2 g103(.a(new_n193), .b(new_n117), .O(new_n194));
  inv1 g104(.a(new_n194), .O(new_n195));
  nor2 g105(.a(new_n195), .b(new_n135), .O(new_n196));
  nor2 g106(.a(new_n196), .b(new_n132), .O(new_n197));
  inv1 g107(.a(new_n123), .O(new_n198));
  nor2 g108(.a(new_n136), .b(\dest_x[17] ), .O(new_n199));
  nor2 g109(.a(new_n199), .b(new_n109), .O(new_n200));
  nor2 g110(.a(\dest_x[4] ), .b(\dest_x[3] ), .O(new_n201));
  inv1 g111(.a(new_n201), .O(new_n202));
  nor2 g112(.a(\dest_x[6] ), .b(\dest_x[5] ), .O(new_n203));
  inv1 g113(.a(new_n203), .O(new_n204));
  nor2 g114(.a(new_n204), .b(new_n202), .O(new_n205));
  inv1 g115(.a(new_n205), .O(new_n206));
  nor2 g116(.a(\dest_x[2] ), .b(\dest_x[1] ), .O(new_n207));
  inv1 g117(.a(new_n207), .O(new_n208));
  nor2 g118(.a(new_n208), .b(new_n160), .O(new_n209));
  inv1 g119(.a(new_n209), .O(new_n210));
  nor2 g120(.a(new_n210), .b(new_n206), .O(new_n211));
  inv1 g121(.a(new_n211), .O(new_n212));
  inv1 g122(.a(new_n98), .O(new_n213));
  nor2 g123(.a(new_n95), .b(\dest_x[13] ), .O(new_n214));
  inv1 g124(.a(new_n214), .O(new_n215));
  nor2 g125(.a(\dest_x[16] ), .b(new_n94), .O(new_n216));
  inv1 g126(.a(new_n216), .O(new_n217));
  nor2 g127(.a(new_n217), .b(new_n215), .O(new_n218));
  inv1 g128(.a(new_n218), .O(new_n219));
  nor2 g129(.a(\dest_x[8] ), .b(\dest_x[7] ), .O(new_n220));
  inv1 g130(.a(new_n220), .O(new_n221));
  nor2 g131(.a(\dest_x[12] ), .b(\dest_x[10] ), .O(new_n222));
  inv1 g132(.a(new_n222), .O(new_n223));
  nor2 g133(.a(new_n223), .b(new_n221), .O(new_n224));
  inv1 g134(.a(new_n224), .O(new_n225));
  nor2 g135(.a(new_n225), .b(new_n219), .O(new_n226));
  inv1 g136(.a(new_n226), .O(new_n227));
  nor2 g137(.a(new_n227), .b(new_n213), .O(new_n228));
  inv1 g138(.a(new_n228), .O(new_n229));
  nor2 g139(.a(new_n229), .b(new_n212), .O(new_n230));
  inv1 g140(.a(new_n230), .O(new_n231));
  nor2 g141(.a(new_n231), .b(new_n200), .O(new_n232));
  inv1 g142(.a(new_n232), .O(new_n233));
  nor2 g143(.a(new_n233), .b(new_n112), .O(new_n234));
  inv1 g144(.a(new_n234), .O(new_n235));
  nor2 g145(.a(new_n235), .b(new_n134), .O(new_n236));
  nor2 g146(.a(new_n236), .b(new_n198), .O(new_n237));
  nor2 g147(.a(new_n237), .b(\dest_x[26] ), .O(new_n238));
  nor2 g148(.a(new_n238), .b(new_n131), .O(new_n239));
  nor2 g149(.a(new_n239), .b(new_n197), .O(new_n240));
  inv1 g150(.a(new_n240), .O(\outport[0] ));
  inv1 g151(.a(\dest_y[27] ), .O(new_n242));
  inv1 g152(.a(\dest_y[25] ), .O(new_n243));
  inv1 g153(.a(\dest_y[24] ), .O(new_n244));
  inv1 g154(.a(\dest_y[23] ), .O(new_n245));
  inv1 g155(.a(\dest_y[20] ), .O(new_n246));
  inv1 g156(.a(\dest_y[19] ), .O(new_n247));
  inv1 g157(.a(\dest_y[17] ), .O(new_n248));
  inv1 g158(.a(\dest_y[15] ), .O(new_n249));
  inv1 g159(.a(\dest_y[14] ), .O(new_n250));
  inv1 g160(.a(\dest_y[11] ), .O(new_n251));
  nor2 g161(.a(\dest_y[10] ), .b(\dest_y[9] ), .O(new_n252));
  nor2 g162(.a(new_n252), .b(new_n251), .O(new_n253));
  nor2 g163(.a(new_n253), .b(\dest_y[12] ), .O(new_n254));
  inv1 g164(.a(new_n254), .O(new_n255));
  nor2 g165(.a(new_n255), .b(\dest_y[13] ), .O(new_n256));
  nor2 g166(.a(new_n256), .b(new_n250), .O(new_n257));
  inv1 g167(.a(new_n257), .O(new_n258));
  nor2 g168(.a(new_n258), .b(new_n249), .O(new_n259));
  nor2 g169(.a(new_n259), .b(\dest_y[16] ), .O(new_n260));
  nor2 g170(.a(new_n260), .b(new_n248), .O(new_n261));
  nor2 g171(.a(new_n261), .b(\dest_y[18] ), .O(new_n262));
  nor2 g172(.a(new_n262), .b(new_n247), .O(new_n263));
  inv1 g173(.a(new_n263), .O(new_n264));
  nor2 g174(.a(new_n264), .b(new_n246), .O(new_n265));
  nor2 g175(.a(new_n265), .b(\dest_y[21] ), .O(new_n266));
  inv1 g176(.a(new_n266), .O(new_n267));
  nor2 g177(.a(new_n267), .b(\dest_y[22] ), .O(new_n268));
  nor2 g178(.a(new_n268), .b(new_n245), .O(new_n269));
  inv1 g179(.a(new_n269), .O(new_n270));
  nor2 g180(.a(new_n270), .b(new_n244), .O(new_n271));
  inv1 g181(.a(new_n271), .O(new_n272));
  nor2 g182(.a(new_n272), .b(new_n243), .O(new_n273));
  nor2 g183(.a(new_n273), .b(\dest_y[26] ), .O(new_n274));
  nor2 g184(.a(new_n274), .b(new_n242), .O(new_n275));
  inv1 g185(.a(new_n275), .O(new_n276));
  inv1 g186(.a(\dest_y[28] ), .O(new_n277));
  inv1 g187(.a(\dest_y[29] ), .O(new_n278));
  nor2 g188(.a(new_n278), .b(new_n277), .O(new_n279));
  inv1 g189(.a(new_n279), .O(new_n280));
  nor2 g190(.a(new_n271), .b(\dest_y[25] ), .O(new_n281));
  nor2 g191(.a(new_n281), .b(new_n273), .O(new_n282));
  inv1 g192(.a(\dest_y[26] ), .O(new_n283));
  inv1 g193(.a(new_n273), .O(new_n284));
  nor2 g194(.a(new_n284), .b(new_n283), .O(new_n285));
  nor2 g195(.a(new_n269), .b(\dest_y[24] ), .O(new_n286));
  nor2 g196(.a(new_n286), .b(new_n271), .O(new_n287));
  inv1 g197(.a(\dest_y[21] ), .O(new_n288));
  nor2 g198(.a(new_n263), .b(\dest_y[20] ), .O(new_n289));
  nor2 g199(.a(new_n289), .b(new_n288), .O(new_n290));
  inv1 g200(.a(\dest_y[13] ), .O(new_n291));
  nor2 g201(.a(new_n254), .b(new_n291), .O(new_n292));
  nor2 g202(.a(\dest_y[4] ), .b(\dest_y[3] ), .O(new_n293));
  inv1 g203(.a(new_n293), .O(new_n294));
  nor2 g204(.a(\dest_y[6] ), .b(\dest_y[5] ), .O(new_n295));
  inv1 g205(.a(new_n295), .O(new_n296));
  nor2 g206(.a(new_n296), .b(new_n294), .O(new_n297));
  inv1 g207(.a(new_n297), .O(new_n298));
  nor2 g208(.a(new_n245), .b(\dest_y[22] ), .O(new_n299));
  inv1 g209(.a(new_n299), .O(new_n300));
  nor2 g210(.a(\dest_y[2] ), .b(\dest_y[1] ), .O(new_n301));
  inv1 g211(.a(new_n301), .O(new_n302));
  nor2 g212(.a(new_n302), .b(new_n300), .O(new_n303));
  inv1 g213(.a(new_n303), .O(new_n304));
  nor2 g214(.a(new_n304), .b(new_n298), .O(new_n305));
  inv1 g215(.a(new_n305), .O(new_n306));
  nor2 g216(.a(\dest_y[12] ), .b(new_n251), .O(new_n307));
  inv1 g217(.a(new_n307), .O(new_n308));
  nor2 g218(.a(\dest_y[16] ), .b(new_n249), .O(new_n309));
  inv1 g219(.a(new_n309), .O(new_n310));
  nor2 g220(.a(new_n310), .b(new_n308), .O(new_n311));
  inv1 g221(.a(new_n311), .O(new_n312));
  nor2 g222(.a(\dest_y[18] ), .b(new_n248), .O(new_n313));
  inv1 g223(.a(new_n313), .O(new_n314));
  nor2 g224(.a(new_n314), .b(new_n247), .O(new_n315));
  inv1 g225(.a(new_n315), .O(new_n316));
  nor2 g226(.a(\dest_y[8] ), .b(\dest_y[7] ), .O(new_n317));
  inv1 g227(.a(new_n317), .O(new_n318));
  inv1 g228(.a(\dest_y[9] ), .O(new_n319));
  nor2 g229(.a(\dest_y[10] ), .b(new_n319), .O(new_n320));
  inv1 g230(.a(new_n320), .O(new_n321));
  nor2 g231(.a(new_n321), .b(new_n318), .O(new_n322));
  inv1 g232(.a(new_n322), .O(new_n323));
  nor2 g233(.a(new_n323), .b(new_n316), .O(new_n324));
  inv1 g234(.a(new_n324), .O(new_n325));
  nor2 g235(.a(new_n325), .b(new_n312), .O(new_n326));
  inv1 g236(.a(new_n326), .O(new_n327));
  nor2 g237(.a(new_n327), .b(new_n306), .O(new_n328));
  inv1 g238(.a(new_n328), .O(new_n329));
  nor2 g239(.a(new_n329), .b(new_n292), .O(new_n330));
  inv1 g240(.a(new_n330), .O(new_n331));
  nor2 g241(.a(new_n331), .b(new_n258), .O(new_n332));
  inv1 g242(.a(new_n332), .O(new_n333));
  nor2 g243(.a(new_n333), .b(new_n266), .O(new_n334));
  inv1 g244(.a(new_n334), .O(new_n335));
  nor2 g245(.a(new_n335), .b(new_n290), .O(new_n336));
  inv1 g246(.a(new_n336), .O(new_n337));
  nor2 g247(.a(new_n337), .b(new_n287), .O(new_n338));
  inv1 g248(.a(new_n338), .O(new_n339));
  nor2 g249(.a(new_n339), .b(new_n285), .O(new_n340));
  inv1 g250(.a(new_n340), .O(new_n341));
  nor2 g251(.a(new_n341), .b(new_n282), .O(new_n342));
  inv1 g252(.a(new_n342), .O(new_n343));
  nor2 g253(.a(\dest_y[0] ), .b(\dest_x[0] ), .O(new_n344));
  inv1 g254(.a(new_n344), .O(new_n345));
  nor2 g255(.a(new_n345), .b(new_n343), .O(new_n346));
  nor2 g256(.a(new_n346), .b(new_n280), .O(new_n347));
  nor2 g257(.a(new_n347), .b(new_n276), .O(new_n348));
  inv1 g258(.a(new_n274), .O(new_n349));
  nor2 g259(.a(new_n349), .b(\dest_y[27] ), .O(new_n350));
  inv1 g260(.a(new_n282), .O(new_n351));
  inv1 g261(.a(new_n287), .O(new_n352));
  nor2 g262(.a(new_n257), .b(new_n248), .O(new_n353));
  nor2 g263(.a(new_n258), .b(\dest_y[17] ), .O(new_n354));
  nor2 g264(.a(new_n354), .b(new_n353), .O(new_n355));
  nor2 g265(.a(new_n247), .b(\dest_y[18] ), .O(new_n356));
  inv1 g266(.a(new_n356), .O(new_n357));
  nor2 g267(.a(\dest_y[26] ), .b(\dest_y[21] ), .O(new_n358));
  inv1 g268(.a(new_n358), .O(new_n359));
  nor2 g269(.a(new_n359), .b(new_n357), .O(new_n360));
  inv1 g270(.a(new_n360), .O(new_n361));
  inv1 g271(.a(\dest_y[7] ), .O(new_n362));
  inv1 g272(.a(\dest_y[8] ), .O(new_n363));
  nor2 g273(.a(new_n363), .b(new_n362), .O(new_n364));
  inv1 g274(.a(new_n364), .O(new_n365));
  nor2 g275(.a(new_n250), .b(\dest_y[13] ), .O(new_n366));
  inv1 g276(.a(new_n366), .O(new_n367));
  nor2 g277(.a(new_n367), .b(new_n365), .O(new_n368));
  inv1 g278(.a(new_n368), .O(new_n369));
  nor2 g279(.a(new_n369), .b(new_n361), .O(new_n370));
  inv1 g280(.a(new_n370), .O(new_n371));
  nor2 g281(.a(new_n371), .b(new_n312), .O(new_n372));
  inv1 g282(.a(new_n372), .O(new_n373));
  inv1 g283(.a(new_n252), .O(new_n374));
  nor2 g284(.a(new_n280), .b(new_n374), .O(new_n375));
  inv1 g285(.a(new_n375), .O(new_n376));
  nor2 g286(.a(new_n376), .b(new_n300), .O(new_n377));
  inv1 g287(.a(new_n377), .O(new_n378));
  inv1 g288(.a(\dest_y[3] ), .O(new_n379));
  inv1 g289(.a(\dest_y[4] ), .O(new_n380));
  nor2 g290(.a(new_n380), .b(new_n379), .O(new_n381));
  inv1 g291(.a(new_n381), .O(new_n382));
  inv1 g292(.a(\dest_y[5] ), .O(new_n383));
  inv1 g293(.a(\dest_y[6] ), .O(new_n384));
  nor2 g294(.a(new_n384), .b(new_n383), .O(new_n385));
  inv1 g295(.a(new_n385), .O(new_n386));
  nor2 g296(.a(new_n386), .b(new_n382), .O(new_n387));
  inv1 g297(.a(new_n387), .O(new_n388));
  inv1 g298(.a(\dest_y[0] ), .O(new_n389));
  nor2 g299(.a(new_n389), .b(\dest_x[0] ), .O(new_n390));
  inv1 g300(.a(new_n390), .O(new_n391));
  inv1 g301(.a(\dest_y[1] ), .O(new_n392));
  inv1 g302(.a(\dest_y[2] ), .O(new_n393));
  nor2 g303(.a(new_n393), .b(new_n392), .O(new_n394));
  inv1 g304(.a(new_n394), .O(new_n395));
  nor2 g305(.a(new_n395), .b(new_n391), .O(new_n396));
  inv1 g306(.a(new_n396), .O(new_n397));
  nor2 g307(.a(new_n397), .b(new_n388), .O(new_n398));
  inv1 g308(.a(new_n398), .O(new_n399));
  nor2 g309(.a(new_n399), .b(new_n378), .O(new_n400));
  inv1 g310(.a(new_n400), .O(new_n401));
  nor2 g311(.a(new_n401), .b(new_n373), .O(new_n402));
  inv1 g312(.a(new_n402), .O(new_n403));
  nor2 g313(.a(new_n403), .b(new_n355), .O(new_n404));
  inv1 g314(.a(new_n404), .O(new_n405));
  nor2 g315(.a(new_n405), .b(new_n265), .O(new_n406));
  inv1 g316(.a(new_n406), .O(new_n407));
  nor2 g317(.a(new_n407), .b(new_n289), .O(new_n408));
  inv1 g318(.a(new_n408), .O(new_n409));
  nor2 g319(.a(new_n409), .b(new_n352), .O(new_n410));
  inv1 g320(.a(new_n410), .O(new_n411));
  nor2 g321(.a(new_n411), .b(new_n351), .O(new_n412));
  inv1 g322(.a(new_n412), .O(new_n413));
  nor2 g323(.a(new_n413), .b(new_n350), .O(new_n414));
  nor2 g324(.a(new_n414), .b(new_n275), .O(new_n415));
  nor2 g325(.a(new_n415), .b(new_n197), .O(new_n416));
  inv1 g326(.a(new_n416), .O(new_n417));
  nor2 g327(.a(new_n417), .b(new_n348), .O(new_n418));
  nor2 g328(.a(new_n418), .b(new_n239), .O(\outport[1] ));
  nor2 g329(.a(new_n389), .b(new_n176), .O(new_n420));
  nor2 g330(.a(new_n420), .b(new_n276), .O(new_n421));
  inv1 g331(.a(new_n421), .O(new_n422));
  nor2 g332(.a(new_n422), .b(new_n343), .O(new_n423));
  nor2 g333(.a(new_n280), .b(new_n276), .O(new_n424));
  inv1 g334(.a(new_n424), .O(new_n425));
  nor2 g335(.a(new_n425), .b(\outport[0] ), .O(new_n426));
  inv1 g336(.a(new_n426), .O(new_n427));
  nor2 g337(.a(new_n427), .b(new_n423), .O(\outport[2] ));
  zero g338(.O(\outport[3] ));
  zero g339(.O(\outport[4] ));
  zero g340(.O(\outport[5] ));
  zero g341(.O(\outport[6] ));
  zero g342(.O(\outport[7] ));
  zero g343(.O(\outport[8] ));
  zero g344(.O(\outport[9] ));
  zero g345(.O(\outport[10] ));
  zero g346(.O(\outport[11] ));
  zero g347(.O(\outport[12] ));
  zero g348(.O(\outport[13] ));
  zero g349(.O(\outport[14] ));
  zero g350(.O(\outport[15] ));
  zero g351(.O(\outport[16] ));
  zero g352(.O(\outport[17] ));
  zero g353(.O(\outport[18] ));
  zero g354(.O(\outport[19] ));
  zero g355(.O(\outport[20] ));
  zero g356(.O(\outport[21] ));
  zero g357(.O(\outport[22] ));
  zero g358(.O(\outport[23] ));
  zero g359(.O(\outport[24] ));
  zero g360(.O(\outport[25] ));
  zero g361(.O(\outport[26] ));
  zero g362(.O(\outport[27] ));
  zero g363(.O(\outport[28] ));
  zero g364(.O(\outport[29] ));
endmodule


