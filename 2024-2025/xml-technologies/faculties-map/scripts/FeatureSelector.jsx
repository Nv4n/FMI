import { FormControl, InputLabel, MenuItem, Select } from "@mui/material";
import { useState } from "react";

export default function FeatureSelector({ features, onFeatureSelected }) {
    const [selectedFeatureIndex, setSelectedFeatureIndex] = useState('');

    const items = features.map((feature, index) =>
        <MenuItem value={index} key={feature.get('name')}>
            { feature.get('name') }
        </MenuItem>
    );

    const handleChange = (event) => {
        const selectedFeatureIndex = event.target.value;
        const selectedFeature = features[selectedFeatureIndex];

        setSelectedFeatureIndex(selectedFeatureIndex);
        onFeatureSelected(selectedFeature);
    }

    return (
        <FormControl fullWidth>
            <InputLabel id="choose-feature-label">Изберете факултет</InputLabel>
            <Select
                labelId="choose-feature-label"
                label="Изберете факултет"
                value={selectedFeatureIndex}
                onChange={handleChange}
            >
                { items }
            </Select>
        </FormControl>
    );
}
