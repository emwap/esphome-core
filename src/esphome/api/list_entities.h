#ifndef ESPHOME_LIST_ENTITIES_H
#define ESPHOME_LIST_ENTITIES_H

#include "esphome/defines.h"

#ifdef USE_API

#include "esphome/component.h"
#include "esphome/api/api_message.h"

ESPHOME_NAMESPACE_BEGIN

namespace api {

class ListEntitiesRequest : public APIMessage {
 public:
  APIMessageType message_type() const override;
};

class APIConnection;

class ListEntitiesIterator : public ComponentIterator {
 public:
  ListEntitiesIterator(APIServer *server, APIConnection *client);
#ifdef USE_BINARY_SENSOR
  bool on_binary_sensor(binary_sensor::BinarySensor *binary_sensor) override;
#endif
#ifdef USE_COVER
  bool on_cover(cover::Cover *cover) override;
#endif
#ifdef USE_FAN
  bool on_fan(fan::FanState *fan) override;
#endif
#ifdef USE_LIGHT
  bool on_light(light::LightState *light) override;
#endif
#ifdef USE_SENSOR
  bool on_sensor(sensor::Sensor *sensor) override;
#endif
#ifdef USE_SWITCH
  bool on_switch(switch_::Switch *switch_) override;
#endif
#ifdef USE_TEXT_SENSOR
  bool on_text_sensor(text_sensor::TextSensor *text_sensor) override;
#endif
  bool on_service(UserServiceDescriptor *service) override;
  bool on_end() override;
 protected:
  APIConnection *client_;
};

} // namespace api

ESPHOME_NAMESPACE_END

#include "esphome/api/api_server.h"

#endif //USE_API

#endif //ESPHOME_LIST_ENTITIES_H
