#ifndef FWCORE_CONVERTOR_H
#define FWCORE_CONVERTOR_H

// LCIO

#include <map>
#include <iostream>
#include <string>
#include "lcio.h"
// #include "IO/LCReader.h"
// #include "EVENT/LCCollection.h"
#include "EVENT/Vertex.h"
#include "EVENT/SimTrackerHit.h"
#include "plcio/SimTrackerHit.h"
#include "plcio/SimTrackerHitCollection.h"
#include "EVENT/SimCalorimeterHit.h"
#include "plcio/SimCalorimeterHit.h"
#include "plcio/SimCalorimeterHitCollection.h"
#include "EVENT/MCParticle.h"
#include "plcio/MCParticle.h"
#include "plcio/MCParticleCollection.h"
#include "plcio/VertexCollection.h"
#include "EVENT/TPCHit.h"
#include "plcio/TPCHit.h"
#include "plcio/TPCHitCollection.h"
#include "EVENT/Cluster.h"
#include "plcio/Cluster.h"
#include "plcio/ClusterCollection.h"
#include "EVENT/ParticleID.h"
#include "EVENT/CalorimeterHit.h"
#include "plcio/CalorimeterHit.h"
#include "podio/CollectionIDTable.h"
#include "EVENT/Track.h" 
#include "EVENT/TrackerHit.h"
#include "EVENT/TrackState.h" 
#include "plcio/Track.h"  
#include "plcio/TrackerHit.h"  
#include "plcio/TrackCollection.h"  
#include "plcio/TrackerHitCollection.h"  
#include "EVENT/ReconstructedParticle.h" 
#include "plcio/ReconstructedParticle.h"  
#include "plcio/ReconstructedParticleCollection.h"  
#include "plcio/ParticleID.h"  
#include "plcio/ParticleIDCollection.h"  

#include <utility>
// Forward declarations

/** @class LCIO2Plcio LCIO2Plcio.h
 *
 *   An LCIO2Plcio for Converting from LCCollection to plcio collection;
 *
 *  @author jhZou, gjCao 
 */

// typedef plcio::MCParticleCollection* (*fptr) (EVENT::LCCollection*);
typedef podio::CollectionBase* (*fptr) (EVENT::LCCollection*);
typedef std::vector<std::pair<EVENT::LCCollection*, podio::CollectionBase*>> CollectionsVec;
typedef std::map<std::string, CollectionsVec> CollectionsMap;

class LCIO2Plcio{
public:

  /// Standard Constructor
  LCIO2Plcio();
  LCIO2Plcio(EVENT::LCCollection*);

  /// Standard Destructor
  virtual ~LCIO2Plcio(){}

  void test(){ printf("MYTESTFUC\n"); }
  void clear(){ map_cols.clear(); };

//  plcio::MCParticleCollection* Convertor_getPlcio(EVENT::LCCollection*);
  podio::CollectionBase* Convertor_getPlcio(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_MCParticle(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_LCRunHeader(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_SimTrackerHit(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_SimCalorimeterHit(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_Cluster(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_Track(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_TrackerHit(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_TPCHit(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_ReconstructedParticle(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_ParticleID(EVENT::LCCollection*);

  static podio::CollectionBase* Convertor_LCRelation(EVENT::LCCollection*);
  static podio::CollectionBase* Convertor_Vertex(EVENT::LCCollection*);

  static void setMCParticle(EVENT::MCParticle*, plcio::MCParticle&);
  void setCollName(const std::string &collName){ CollName = collName; };

  bool isReady(const std::string&);

private:
  std::string TypeName;
  static std::string CollName;
  // maintain a log vec about data read;
  std::vector<std::string> vec_Types;

  // maintain a map from keyword to function pointer.
  std::map<std::string, fptr> map_cvt;
  static CollectionsMap map_cols;

//  plcio::MCParticleCollection* hitcol_pl;
//  EVENT::LCCollection* hitcol_lc;
};
#endif  // CORE_CONVERTOR_H
