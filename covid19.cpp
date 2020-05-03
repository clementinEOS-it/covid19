#include "covid19.hpp"
#include <eosio/eosio.hpp>
#include <eosio/time.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>

using namespace std;
using namespace eosio;

// Add or update record in covid table
ACTION covid19::send(string      dateISO,
                    checksum256     key,
                    checksum256     source_hash,
                    double          lat,
                    double           lng,
                    int64_t          hws,          
                    int64_t          ic,           
                    int64_t          to,           
                    int64_t          hi,           
                    int64_t          tot_cp,       
                    int64_t          tot_new_cp,  
                    int64_t          dh,          
                    int64_t          dead,         
                    int64_t          tot_c,        
                    int64_t          sw,
                    int64_t          tc) {

  require_auth(get_self());
  
  // Init the _message table
  virus_t _inf(get_self(), get_self().value);

  // -----------------------------------------
  // find element by hash key

  auto i_byhash = _inf.get_index<"byhash"_n>();
  const auto i = i_byhash.find(key); 

  if ( i == i_byhash.end() ) {

    _inf.emplace(get_self(), [&](auto& item) {
      item.from = get_self();
      item.id = _inf.available_primary_key();
      item.date_at = dateISO;
      item.id_hash = key;   
      item.source_hash = source_hash;
      item.lat = lat;                 // Latitude
      item.lng = lng;                 // Longitude
      item.hws = hws;                 // Hospitalized with symptoms
      item.ic = ic;                   // Intensive care
      item.to = to;                   // Total hospitalized
      item.hi = hi;                   // Home isolation
      item.tot_cp = tot_cp;           // currently positive
      item.tot_new_cp = tot_new_cp;   // currently positive
      item.dh = dh;                   // discharged healed
      item.dead = dead;               // deceased
      item.tot_c = tot_c;             // total cases
      item.sw = sw;                   // virus swab
      item.tc = tc;                   // tested cases
    });
  
  } else {

    i_byhash.modify(i, get_self(), [&]( auto& item ) {
      item.source_hash = source_hash;
      item.lat = lat;           
      item.lng = lng;           
      item.hws = hws;           
      item.ic = ic;             
      item.to = to;             
      item.hi = hi;              
      item.tot_cp = tot_cp;       
      item.tot_new_cp = tot_new_cp;   
      item.dh = dh;           
      item.dead = dead;         
      item.tot_c = tot_c;        
      item.sw = sw;           
      item.tc = tc;
    });
  }
}

// Delete all records in covid table
ACTION covid19::clear(uint64_t id) {

  require_auth(get_self());

  virus_t _inf(get_self(), get_self().value);
  const auto i = _inf.find(id); 

  if ( i == _inf.end() ) {
    auto item = _inf.begin();
    while (item != _inf.end()) {
      item = _inf.erase(item);
    }
  } else {
    _inf.erase(i);
  }
}

EOSIO_DISPATCH(covid19, 
               (send)
               (clear));
