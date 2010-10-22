/**
 * The Seeks proxy and plugin framework are part of the SEEKS project.
 * Copyright (C) 2010 Emmanuel Benazera, juban@free.fr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef JSON_RENDERER_H
#define JSON_RENDERER_H

#include "websearch.h"
#include "clustering.h"

namespace seeks_plugins
{
   class json_renderer
     {
      public:
	static sp_err render_snippets(const int &current_page,
				      const std::vector<search_snippet*> &snippets,
				      std::string &json_str,
				      const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters);
	
	static sp_err render_clustered_snippets(cluster *clusters, const short &K,
						const query_context *qc,
						std::string &json_str,
						const hash_map<const char*,const char*,hash<const char*>,eqstr> *parameters);
	
	static sp_err render_json_results(const std::vector<search_snippet*> &snippets,
					  client_state *csp, http_response *rsp,
					  const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
					  const query_context *qc,
					  const double &qtime);
	
	static sp_err render_clustered_json_results(cluster *clusters,
						    const short &K,
						    client_state *csp, http_response *rsp,
						    const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
						    const query_context *qc,
						    const double &qtime);
     };
} /* end of namespace. */

#endif
