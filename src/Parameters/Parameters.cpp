#include "Parameters.hpp"
#include "../Logger/BKeeperLog.hpp"


#define CheckParameterExists(param_name) if (reader.push( param_name )) { reader.pop(); } else { std::cout << BKeeperLogMessage << "Error: '" << param_name << "' not defined in parameter file. Aborting." << std::endl; missing_params=true; }

bool readParameterFile(BKeeperParameters& out, std::string& filepath)
{
    bool missing_params=false;
    Grid::XmlReader reader(filepath);
    CheckParameterExists("iterations");
    CheckParameterExists("mass");
    CheckParameterExists("benchmarks");
    
    if (missing_params)
        return false;
    
    read(reader, "iterations", out.iterations);
    read(reader, "mass",       out.mass);
    read(reader, "benchmarks", out.benchmarks);
    return true;
}

#undef CheckParameterExists

