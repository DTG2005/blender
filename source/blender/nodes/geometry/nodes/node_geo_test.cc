/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#include <fstream>

#include <fmt/format.h>

#include "NOD_node_extra_info.hh"
#include "NOD_rna_define.hh"
#include "NOD_zone_socket_items.hh"

#include "UI_interface.hh"
#include "UI_resources.hh"

#include "BLI_string.h"

#include "BKE_bake_geometry_nodes_modifier.hh"
#include "BKE_bake_items_socket.hh"
#include "BKE_context.hh"
#include "BKE_screen.hh"

#include "ED_node.hh"

#include "DNA_modifier_types.h"

#include "RNA_access.hh"
#include "RNA_prototypes.h"

#include "MOD_nodes.hh"

#include "WM_api.hh"

#include "node_geometry_util.hh"

namespace blender::nodes::node_geo_test_cc {

static void node_declare(NodeDeclarationBuilder &b)
{
  b.add_input<decl::Geometry>("Input");
  b.add_output<decl::Geometry>("Output");
}

static void node_geo_exec(GeoNodeExecParams params)
{
  GeometrySet gs = params.extract_input<GeometrySet>("Input");
  geometry::translate_geometry(gs, {0, 20, 0});
  params.set_output("Output", gs);
}

static void node_register()
{
  static bNodeType ntype;

  geo_node_type_base(&ntype, GEO_NODE_TEST, "Testing", NODE_CLASS_INTERFACE);
  ntype.geometry_node_execute = node_geo_exec;
  ntype.declare = node_declare;
  nodeRegisterType(&ntype);
}
NOD_REGISTER_NODE(node_register);

};  // namespace blender::nodes::node_geo_test_cc
