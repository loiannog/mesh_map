/*created by
 *Giuseppe Loianno and Sadat Shaik*/

#include <mesh_map/mesh_map.h>




void cloud_callback(const sensor_msgs::PointCloud2::ConstPtr& msg) {
    
    		      pcl::PointCloud <pcl::PointXYZ> map_pcl;
		      sensor_msgs::PointCloud2 in_points2;
		      pcl::fromROSMsg(in_points2, map_pcl);
		      //map_pcl has a size
  }

  

  
  
int main(int argc, char** argv) {
  ros::init(argc, argv, "mesh_map");
  //set the nodehandkle
  ros::NodeHandle nh_("~");
  // set the parameters
  ros::Subscriber subpointcloud_ = nh_.subscribe("map", 10, &cloud_callback, ros::TransportHints().tcpNoDelay());
  //call all the callback
  ros::spin();

  return 0;
};



