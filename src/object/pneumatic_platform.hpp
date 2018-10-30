//  SuperTux - PneumaticPlatform
//  Copyright (C) 2007 Christoph Sommer <christoph.sommer@2007.expires.deltadevelopment.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_OBJECT_PNEUMATIC_PLATFORM_HPP
#define HEADER_SUPERTUX_OBJECT_PNEUMATIC_PLATFORM_HPP

#include "object/moving_sprite.hpp"

class PneumaticPlatform;

class PneumaticPlatformChild final : public MovingSprite
{
  friend class PneumaticPlatform;

public:
  PneumaticPlatformChild(const ReaderMapping& reader, bool left, PneumaticPlatform& parent);
  virtual ~PneumaticPlatformChild();

  virtual HitResponse collision(GameObject& other, const CollisionHit& hit) override;
  virtual void update(float dt_sec) override;

protected:
  PneumaticPlatform& m_parent;
  bool m_left;
  std::set<GameObject*> m_contacts; /**< objects that are currently pushing on the platform */

private:
  PneumaticPlatformChild(const PneumaticPlatformChild&);
  PneumaticPlatformChild& operator=(const PneumaticPlatformChild&);
};

/**
 * Used to construct a pair of pneumatic platforms: If one is pushed down, the other one rises
 */
class PneumaticPlatform final : public GameObject
{
  friend class PneumaticPlatformChild;

public:
  PneumaticPlatform(const ReaderMapping& mapping);
  virtual ~PneumaticPlatform();

  virtual void draw(DrawingContext& context) override;
  virtual void update(float dt_sec) override;
  virtual std::string get_class() const override {
    return "pneumatic-platform";
  }
  virtual std::string get_display_name() const override {
    return _("Pneumatic platform");
  }

  virtual void after_editor_set() override;
  virtual void editor_delete() override;

protected:
  float m_start_y; /**< vertical start position */
  float m_speed_y; /**< vertical speed */
  float m_offset_y; /**< vertical offset from the start position in px */
  std::vector<PneumaticPlatformChild*> m_children;

private:
  PneumaticPlatform(const PneumaticPlatform&);
  PneumaticPlatform& operator=(const PneumaticPlatform&);
};

#endif

/* EOF */
