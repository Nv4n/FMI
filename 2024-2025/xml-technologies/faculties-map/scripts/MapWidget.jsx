import { Map, View } from 'ol';
import { createEmpty, extend } from 'ol/extent';
import TileLayer from 'ol/layer/Tile';
import VectorLayer from 'ol/layer/Vector';
import { fromLonLat } from 'ol/proj';
import OSM from 'ol/source/OSM';
import { useEffect, useRef } from "react";

const DEFAULT_CENTER = fromLonLat([23.3217583, 42.697128]);

const DEFAULT_ZOOM = 14;
const FOCUSED_ZOOM = 17;

export default function MapWidget({ layerSource, feature }) {
    const mapContainerRef = useRef(null);
    const mapRef = useRef(null);

    useEffect(() => {
        if (mapRef.current === null) {
            const container = mapContainerRef.current;
            mapRef.current = createMap(container);
        }
        const map = mapRef.current;

        if (layerSource) {
            const layer = createVectorLayer(layerSource);
            map.addLayer(layer);
        }

        map.setView(createView(layerSource, feature));

        return () => {
            map.setView(createDefaultView());
            map.setLayers(createDefaultMapLayers());
        };
    }, [layerSource, feature]);

    return  <div className="map" ref={mapContainerRef} />;
};

function createMap(container) {
    return new Map({
        target: container,
        layers: createDefaultMapLayers(),
    });
}

function createDefaultMapLayers() {
    return [new TileLayer({ source: new OSM() })];
}

function createVectorLayer(source) {
    return new VectorLayer({ source });
}

function createView(layerSource, feature) {
    if (feature) {
        return createViewForFeature(feature);
    } else if (layerSource?.getFeatures()?.length > 0) {
        return createViewForFeatures(layerSource.getFeatures());
    } else {
        return createDefaultView();
    }
}

function createViewForFeature(feature) {
    return new View({
        center: feature.getGeometry().getCoordinates(),
        zoom: FOCUSED_ZOOM,
    });
}

function createViewForFeatures(features) {
    const view = new View();

    const extents = features.map(feature => feature.getGeometry().getExtent());
    const extent = extents.reduce(extend, createEmpty())
    view.fit(extent);
    view.setZoom(DEFAULT_ZOOM);

    return view;
}

function createDefaultView() {
    return new View({
        center: DEFAULT_CENTER,
        zoom: DEFAULT_ZOOM,
    });
}
