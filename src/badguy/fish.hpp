//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
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

#ifndef HEADER_SUPERTUX_BADGUY_FISH_HPP
#define HEADER_SUPERTUX_BADGUY_FISH_HPP

#include "badguy/badguy.hpp"

class Fish final : public BadGuy
{
public:
  Fish(const ReaderMapping& );

  virtual void draw(DrawingContext& context) override;

  virtual void collision_solid(const CollisionHit& hit) override;
  virtual HitResponse collision_badguy(BadGuy& , const CollisionHit& ) override;
  virtual void collision_tile(uint32_t tile_attributes) override;

  virtual void active_update(float) override;

  virtual void freeze() override;
  virtual void unfreeze(bool melt = true) override;
  virtual void kill_fall() override;
  virtual bool is_freezable() const override;
  virtual std::string get_class() const override { return "fish"; }
  virtual std::string get_display_name() const override { return _("Fish"); }
  virtual std::string get_overlay_size() const override { return "1x2"; }

private:
  HitResponse hit(const CollisionHit& );
  void start_waiting();
  void jump();

  Timer waiting;
  float stop_y; /**< y-coordinate to stop at */
};

#endif

/* EOF */
