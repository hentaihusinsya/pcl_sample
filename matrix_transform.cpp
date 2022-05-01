#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
// This function displays the help
void showHelp(char* program_name)
{
	std::cout << std::endl;
	std::cout << "Usage: " << program_name << " cloud_filename.[pcd|ply]" << std::endl;
	std::cout << "-h: Show this help." << std::endl;
}
//This is the main function
int main (int argc, char** argv)
{	// Show help
	if (pcl::console::find_switch (argc, argv, "-h") || pcl::console::find_switch (argc, argv, "--help")){ showHelp (argv[0]);
		return 0;
}
//Fetch point cloud 
std::vector<int> filenames;
bool file_is_pcd = false;

filenames = pcl::console::parse_file_extension_argument (argc, argv, ".ply");

if (filenames.size () != 1) {
	filenames = pcl::console::parse_file_extension_argument (argc, argv, ".pcd");

	if (filenames.size () != 1) {
		showHelp (argv[0]);
		return -1;
	}
	else{
		file_is_pcd = true;
	}
}

// Load file | Works with PCD and PLY files
pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud (new pcl::PointCloud<pcl:PointXYZ> ());

if (file_is_pcd){
	if (pcl::io::loadPCDFile (argv[filenames[0]], *source_cloud) < 0) {
		std::cout << "Error loading point cloud" << argv
