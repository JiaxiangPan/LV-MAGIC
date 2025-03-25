# LV-MAGIC: Logic Synthesis and Verification for MAGIC based In-Memory Computing

LV-MAGIC is based on the [alice](https://github.com/lsils/alice), and it can be used for logic synthesis and verification based on memristor-aided logic.

## Requirements
### A modern compiler is required to build the libraries. Compiled successfully with Clang 6.0.1, Clang 12.0.0, GCC 7.3.0, and GCC 8.2.0. 

### Open-Source Logic Synthesis Tools [abc](https://github.com/berkeley-abc/abc)

## How to Compile
```bash
mkdir build
cd build
cmake ..
make
```

## Recommended Related Papers
S. Kvatinsky et al., "MAGIC—Memristor-Aided Logic," in IEEE Transactions on Circuits and Systems II: Express Briefs, vol. 61, no. 11, pp. 895-899, Nov. 2014, doi: 10.1109/TCSII.2014.2357292.

R. Ben Hur, N. Wald, N. Talati and S. Kvatinsky, "Simple magic: Synthesis and in-memory Mapping of logic execution for memristor-aided logic," 2017 IEEE/ACM International Conference on Computer-Aided Design (ICCAD), Irvine, CA, USA, 2017, pp. 225-232, doi: 10.1109/ICCAD.2017.8203782.

R. Ben-Hur et al., "SIMPLER MAGIC: Synthesis and Mapping of In-Memory Logic Executed in a Single Row to Improve Throughput," in IEEE Transactions on Computer-Aided Design of Integrated Circuits and Systems, vol. 39, no. 10, pp. 2434-2447, Oct. 2020, doi: 10.1109/TCAD.2019.2931188. 

S. Rai et al., "Perspectives on Emerging Computation-in-Memory Paradigms," 2021 Design, Automation & Test in Europe Conference & Exhibition (DATE), Grenoble, France, 2021, pp. 1925-1934, doi: 10.23919/DATE51398.2021.9473976.

M. R. Haq Rashed, S. Kumar Jha and R. Ewetz, "Logic Synthesis for Digital In-Memory Computing," 2022 IEEE/ACM International Conference On Computer Aided Design (ICCAD), San Diego, CA, USA, 2022, pp. 1-9.

J. Pan and Z. Chu, "Area-Aware Logic Mapping for MAGIC based In-Memory Computing," 2024 20th International Conference on Synthesis, Modeling, Analysis and Simulation Methods and Applications to Circuit Design (SMACD), Volos, Greece, 2024, pp. 1-4, doi: 10.1109/SMACD61181.2024.10745461.

C. K. Jha et al., "veriSIMPLER: An Automated Formal Verification Methodology for SIMPLER MAGIC Design Style Based In-Memory Computing," in IEEE Transactions on Circuits and Systems I: Regular Papers, vol. 71, no. 9, pp. 4169-4179, Sept. 2024, doi: 10.1109/TCSI.2024.3424682.

## Recommended Related Repositories
[https://github.com/RotemBenHur/SIMPLE-MAGIC]

[https://github.com/RotemBenHur/SIMPLER-MAGIC]

[https://github.com/debjyoti0891/MAGICNetlistGen]

[https://github.com/debjyoti0891/arche]

[https://github.com/MionaSHEN/Staircase-Mapping-S]