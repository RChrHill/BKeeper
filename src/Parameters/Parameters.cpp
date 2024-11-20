#include "Parameters.hpp"


BKeeperParameters readParameterFile(std::string& filepath)
{
    BKeeperParameters out;

    Grid::XmlReader reader(filepath);
    read(reader, "iterations", out.iterations);
    read(reader, "mass",       out.mass);
    read(reader, "benchmarks", out.benchmarks);
    return out;
}
