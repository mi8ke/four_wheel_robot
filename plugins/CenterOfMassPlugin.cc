#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/PhysicsEngine.hh>

namespace gazebo
{
  class CenterOfMassPlugin : public ModelPlugin
  {
  public:
    CenterOfMassPlugin() {}

    virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
      this->model = _model;

      this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&CenterOfMassPlugin::OnUpdate, this));
    }

    void OnUpdate()
    {
      math::Vector3 centerOfMass = this->model->GetWorldCoGPose().pos;
      std::cout << "Center of mass: "x=" << centerOfMass.x << , y=" << centerOfMass.y << ", z=" << centerOfMass.z << std::endl;
    }

private:
physics::ModelPtr model;
event::ConnectionPtr updateConnection;
};

GZ_REGISTER_MODEL_PLUGIN(CenterOfMassPlugin)
}