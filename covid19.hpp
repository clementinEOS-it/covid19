#include <eosio/eosio.hpp>
#include <eosio/crypto.hpp>
#include <eosio/eosio.hpp>
#include <eosio/time.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>

using namespace std;
using namespace eosio;

CONTRACT covid19 : public contract {
  public:
    using contract::contract;

    ACTION send(string      dateISO,
                checksum256 key,
                checksum256 source_hash,
                double      lat,
                double      lng,
                int64_t     hws,          // Hospitalized with symptoms
                int64_t     ic,           // Intensive care
                int64_t     to,           // Total hospitalized
                int64_t     hi,           // Home isolation
                int64_t     tot_cp,       // currently positive
                int64_t     tot_new_cp,   // currently positive
                int64_t     dh,           // discharged healed
                int64_t     dead,         // deceased
                int64_t     tot_c,        // total cases
                int64_t     sw,
                int64_t     tc);
    ACTION clear(uint64_t id);
              
  private:
    TABLE virusdata {
      name              from;
      uint64_t          id;           
      string            date_at;      // date
      eosio::checksum256   id_hash;      // id
      eosio::checksum256   source_hash;  // url sorce opendata
      double            lat;          // Latitude
      double            lng;          // Longitude
      int64_t           hws;          // Hospitalized with symptoms
      int64_t           ic;           // Intensive care
      int64_t           to;           // Total hospitalized
      int64_t           hi;           // Home isolation
      int64_t           tot_cp;       // currently positive
      int64_t           tot_new_cp;   // currently positive
      int64_t           dh;           // discharged healed
      int64_t           dead;         // deceased
      int64_t           tot_c;        // total cases
      int64_t           sw;           // virus swab
      int64_t           tc;           // tested cases
      
      uint64_t primary_key() const { 
        return id; 
      }

      checksum256 by_hash() const { 
        return id_hash; 
      }

      checksum256 by_source_hash() const { 
        return source_hash; 
      }

    };

    typedef multi_index<
      "virusdata"_n,
      virusdata,
      indexed_by<"byhash"_n, const_mem_fun<virusdata, checksum256, &virusdata::by_hash>>,
      indexed_by<"bysource"_n, const_mem_fun<virusdata, checksum256, &virusdata::by_source_hash>>>
      virus_t;

};
